/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:54:27 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/21 22:04:33 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// HOX Only call this function if you know that an alignment needs to be done,
// i.e. F_LEFT_ALIGN is set!
int	align_left(t_fstring *fs, char *left_adjusted_str)
{
	if (fs->field_width > fs->len)
	{
		if (!left_adjusted_str)
			return (-1);
		ft_memmove(left_adjusted_str, fs->string, fs->len);
		free(fs->string);
		fs->string = left_adjusted_str;
	}
	return (0);
}

int	expand_to_field_width(t_fstring *fs)
{
	char			*expanded;

	if (fs->field_width > fs->len)
	{
		expanded = ft_strnew(fs->field_width);
		if (!expanded)
			return (-1);
		if (fs->format & F_ZERO_PAD)
			ft_memset(expanded, '0', fs->field_width);
		else
			ft_memset(expanded, ' ', fs->field_width);
		if (fs->format & F_LEFT_ALIGN)
			align_left(fs, expanded);
		else
		{
			ft_memcpy(expanded + (fs->field_width - fs->len),\
					fs->string, fs->len);
			free(fs->string);
			fs->string = expanded;
		}
		fs->len = fs->field_width;
	}
	return (0);
}
