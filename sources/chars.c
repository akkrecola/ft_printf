/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:37:42 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/21 23:54:09 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_string(t_fstring *fs, const char *arg)
{
	if (arg == NULL)
		fs->string = ft_strdup("(null)");
	else if (fs->format & EXPL_PRECISION)
		fs->string = ft_strndup(arg, fs->precision);
	else
		fs->string = ft_strdup(arg);
	fs->len = ft_strlen(fs->string);
	if (fs->field_width > ft_strlen(fs->string))
		expand_to_field_width(fs);
	return (3);
}

int	convert_char(t_fstring *fs, unsigned char arg)
{
	fs->string = ft_strnew(1);
	fs->string[0] = arg;
	fs->len = 1;
	if (fs->field_width > fs->len)
		expand_to_field_width(fs);
	return (4);
}

int	give_percent(t_fstring *fs)
{
	fs->string = ft_strdup("%");
	fs->len = 1;
	if (fs->field_width > fs->len)
		expand_to_field_width(fs);
	return (7);
}
