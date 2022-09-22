/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:37:42 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/23 02:09:16 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_string(t_fstring *fs, va_list *ap)
{
	const char	*arg = (const char *)va_arg(*ap, char *);

	if (arg == NULL)
		fs->string = ft_strdup("(null)");
	else if (fs->format & EXPL_PRECISION)
		fs->string = ft_strndup(arg, fs->precision);
	else
		fs->string = ft_strdup(arg);
	if (!fs->string)
		return (0);
	fs->len = ft_strlen(fs->string);
	if (fs->field_width > ft_strlen(fs->string))
		expand_to_field_width(fs);
	return (3);
}

int	convert_char(t_fstring *fs, va_list *ap)
{
	const unsigned char	c = (const unsigned char)va_arg(*ap, int);

	fs->string = ft_strnew(1);
	if (!fs->string)
		return (0);
	fs->string[0] = c;
	fs->len = 1;
	if (fs->field_width > fs->len)
		expand_to_field_width(fs);
	return (4);
}

int	give_percent(t_fstring *fs, va_list *ap) // No conversion -> ap is no-op
{
	(void)ap; // no-op, shut up gcc
	fs->string = ft_strdup("%");
	if (!fs->string)
		return (0);
	fs->len = 1;
	if (fs->field_width > fs->len)
		expand_to_field_width(fs);
	return (7);
}
