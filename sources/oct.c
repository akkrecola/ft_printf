/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 05:21:34 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/25 17:32:29 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define OCT_DIV 8
#define OCT_BUFSIZE 32

/* Convert decimal to octal representation. The resulting string is
 * collected reversed, and is reversed back in it's caller.
 */
static int	build_oct(unsigned long long int arg, uint8_t div, char *buf)
{
	if (!arg)
		return (div);
	*buf = build_oct(arg / OCT_DIV, arg % OCT_DIV, buf + 1) + '0';
	return (div);
}

/* Format an unsigned integer argument in octal notation.
 * Calls on recursive builder build_oct()
 */
void	format_oct(unsigned long long int arg, t_fstring *fs)
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
	if (!fs->string)
		error(fs);
	if (fs->string && fs->format & F_ALT_FORM && arg != 0 && !fs->sign)
		prepend_sign(fs);
	fs->len = ft_strlen(fs->string);
}
