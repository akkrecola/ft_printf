/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:20:05 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/25 17:28:18 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define HEX_DIVIDEND 16
#define HEX_BUFSIZE 32

/* Adds the correct (upper- or lowercase) hex notation prefix to a string.
 */
void	add_hex_prefix(t_fstring *fs)
{
	char	*prepended;

	prepended = ft_strnew(fs->len + 2);
	if (!prepended)
		error(fs);
	prepended[0] = '0';
	if (*fs->type == 'X')
		prepended[1] = 'X';
	else
		prepended[1] = 'x';
	ft_memmove(prepended + 2, fs->string, fs->len);
	ft_strdel(&fs->string);
	fs->string = prepended;
	fs->len += 2;
}

/* Converts a decimal (base-10) notation to base-16, and returns it in a string.
 */
static char	*build_hex(unsigned long arg, int is_uppercase)
{
	char	buf[HEX_BUFSIZE];
	char	current;
	int		remainder;

	ft_bzero(&buf[0], HEX_BUFSIZE);
	current = 0;
	remainder = 0;
	while (arg > 0)
	{
		remainder = arg % HEX_DIVIDEND;
		if (remainder >= 10)
		{
			if (is_uppercase)
				current = remainder + 55;
			else
				current = remainder + 87;
		}
		else
			current = remainder + '0';
		ft_charappend(buf, current);
		arg /= HEX_DIVIDEND;
	}
	return (ft_strrev(buf));
}

/* Convert a clean integer value to a hex format string. Basically an outside 
 * caller for build_hex(), but handles a 0 input on top.
 */
void	format_hex(unsigned long long int arg, t_fstring *fs)
{
	if (arg == 0)
		set_explicit_zero(fs);
	else
		fs->string = build_hex(arg, ((fs->format & CMASK) == C_UHEX_CAP));
	if (!fs->string)
		error(fs);
	fs->len = ft_strlen(fs->string);
}

/* Converts a void * argument into an hex memory address
 * notation.
 */
void	convert_void(t_fstring *fs, va_list *ap)
{
	const long long	arg = (long long)(long long *)va_arg(*ap, void *);
	char			*temp_str;

	format_hex(arg, fs);
	temp_str = ft_strsub(fs->string, 0, 14);
	if (!temp_str)
		error(fs);
	ft_strdel(&fs->string);
	fs->string = temp_str;
	fs->len = ft_strlen(fs->string);
	pad_integer_precision(fs);
	add_hex_prefix(fs);
	fs->len = ft_strlen(fs->string);
	if (fs->field_width > fs->len)
		expand_to_field_width(fs);
}
