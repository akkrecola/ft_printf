/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:20:05 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/23 09:01:14 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define HEX_DIVIDEND 16
#define HEX_BUFSIZE 32
#define OCT_DIV 8
#define OCT_BUFSIZE 32

// Adds the correct hex prefix to a string
int	add_hex_prefix(t_fstring *fs)
{
	char	*prepended;

	prepended = ft_strnew(fs->len + 2);
	if (!prepended)
		return (0);
	prepended[0] = '0';
	if (*fs->type == 'X')
		prepended[1] = 'X';
	else
		prepended[1] = 'x';
	ft_memmove(prepended + 2, fs->string, fs->len);
	free(fs->string);
	fs->string = prepended;
	fs->len += 2;
	return (1);
}

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
				current = remainder + 55; // 10 -> A
			else
				current = remainder + 87; // 10 -> a
		}
		else
			current = remainder + '0'; // 9 -> 7
		ft_charappend(buf, current);
		arg /= HEX_DIVIDEND; // NOTE: integer division
	}
	return (ft_strrev(buf));
}

// Convert a clean integer value to a hex format string.
// First one to call on hex conversions (before precision and fwidth)
int	format_hex(unsigned long long int arg, t_fstring *fs)
{
	if (arg == 0)
	{
		set_explicit_zero(fs);
		return (1);
	}
	else
	{
		fs->string = build_hex(arg, ((fs->format & CMASK) == C_UHEX_CAP));
		if (!fs->string)
			return (0); // malloc protecc
		fs->len = ft_strlen(fs->string);
		return (2);
	}
	return (0);
}

// Convert decimal to octal representation. The resulting string is
// collected reversed, and is reversed back in caller.
static int	build_oct(unsigned long long int arg, uint8_t div, char *buf)
{
	if (!arg)
		return (div);
	*buf = build_oct(arg / OCT_DIV, arg % OCT_DIV, buf + 1) + '0';
	return (div);
}

int	format_oct(unsigned long long int arg, t_fstring *fs)
{
	char	buf[OCT_BUFSIZE];

	ft_bzero(&buf[0], OCT_BUFSIZE);
	if (arg == 0)
		set_explicit_zero(fs);
	else
	{
		build_oct(arg, arg % OCT_DIV, &buf[0]);
		fs->string = ft_strrev(&buf[0]);
		if (!fs->string)
			return (0);
	}
	if (fs->format & F_ALT_FORM && arg != 0)
		prepend_sign(fs);
	fs->len = ft_strlen(fs->string);
	return (1);
}

int	convert_void(t_fstring *fs, va_list *ap)
{
	const long long	arg = (long long)(long long *)va_arg(*ap, void *);
	char			*temp_str;

	format_hex(arg, fs);
	if (!fs->string)
		return (0);
	temp_str = ft_strsub(fs->string, 0, 14);
	if (!temp_str)
		return (0);
	free(fs->string);
	fs->string = temp_str;
	fs->len = ft_strlen(fs->string);
	pad_integer_precision(fs);
	add_hex_prefix(fs);
	fs->len = ft_strlen(fs->string);
	if (fs->field_width > fs->len)
		expand_to_field_width(fs);
	return (6);
}
