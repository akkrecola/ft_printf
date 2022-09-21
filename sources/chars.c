/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:37:42 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/20 21:43:28 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_string(t_fstring *fs, const char *arg)
{
	if (fs->format & EXPL_PRECISION)
		fs->string = ft_strndup(arg, fs->precision);
	else
		fs->string = ft_strdup(arg);
	if (fs->field_width > ft_strlen(fs->string))
		expand_to_field_width(fs);
	return (3);
}

int	convert_char(t_fstring *fs, unsigned char arg)
{
	fs->string = ft_strnew(1);
	*fs->string = arg;
	if (fs->field_width > 1)
		expand_to_field_width(fs);
	return (4);
}

int	give_percent(t_fstring *fs)
{
	fs->string = ft_strdup("%");
	return (7);
}
