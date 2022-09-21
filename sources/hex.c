/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:20:05 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/22 01:16:45 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#define HEX_DIVIDEND 16
#define HEX_BUFSIZE 32
#define OCT_DIV 8
#define OCT_BUFSIZE 32

// Adds the correct hex prefix to a string
void	add_hex_prefix(t_fstring *fs)
{
	char	*prepended;

	prepended = ft_strnew(ft_strlen(fs->string) + 2);
	if (!prepended)
		return ;
	prepended[0] = '0';
	if (*fs->type == 'X')
		prepended[1] = 'X';
	else
		prepended[1] = 'x';
	ft_strcpy(prepended + 2, fs->string);
	free(fs->string);
	fs->string = prepended;
}

static char	*build_hex(unsigned long arg, char *buf, int is_uppercase)
{
	char	current;
	int		remainder;
	
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
char	*format_hex(unsigned long long arg, t_fstring *fs)
{
	char	buf[HEX_BUFSIZE]; // max hex format length is about 16 bytes
	char	*rev_base;

	if (arg == 0)
		return (ft_strdup("0"));
	ft_bzero(&buf[0], HEX_BUFSIZE);
	rev_base = build_hex(arg, &buf[0], (fs->format & C_UHEX_CAP));
	ft_strcpy(&buf[0], rev_base);
	free(rev_base);
	return (ft_strdup(&buf[0]));
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

char	*format_oct(unsigned long long int arg, t_fstring *fs)
{
	char	buf[OCT_BUFSIZE];

	ft_bzero(&buf[0], OCT_BUFSIZE);
	if (arg == 0)
		set_explicit_zero(fs);
	else
	{
		build_oct(arg, arg % OCT_DIV, &buf[0]);
		fs->string = ft_strrev(&buf[0]);
	}
	if (fs->format & F_ALT_FORM && arg != 0)
		prepend_sign(fs);
	fs->len = ft_strlen(fs->string);
	return (fs->string);
}

int	convert_void(t_fstring *fs, void *arg)
{
	const long long	address = (long long)*((long long *)arg);
	char			*temp_str;

	fs->string = format_hex(address, fs);
	if (!fs->string)
		return (0);
	temp_str = ft_strsub(fs->string, 0, 14);
	free(fs->string);
	fs->string = temp_str;
	return (6);
}
