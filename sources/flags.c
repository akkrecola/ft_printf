/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:54:27 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/19 08:27:24 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// HOX Only call this function if you know that an alignment needs to be done,
// i.e. F_LEFT_ALIGN is set!
int	align_left(t_fstring *fs, char *left_adjusted_str)
{
	// If left justification specified and field width allows space
	if (fs->field_width > ft_strlen(fs->string))
	{
		if (!left_adjusted_str)
			return (-1);
		ft_memmove(left_adjusted_str, fs->string, ft_strlen(fs->string));
		free(fs->string);
		fs->string = left_adjusted_str;
	}
	return (0);
}

int	expand_to_field_width(t_fstring *fs)
{
	char			*expanded;

	if (fs->field_width > ft_strlen(fs->string))
	{
		expanded = ft_strnew(fs->field_width);
		if (!expanded)
			return (-1);
		if (fs->format & F_ZERO_PAD) // any precision overrides zero flag (GNU printf) TODO TEST THE EXPL_PRECISION CHECK MOVE TO MODIFIERS.C
			ft_memset(expanded, '0', fs->field_width);
		else
			ft_memset(expanded, ' ', fs->field_width);
		if (fs->format & F_LEFT_ALIGN)
			align_left(fs, expanded);
		else
		{
			ft_strcpy(expanded + (fs->field_width - ft_strlen(fs->string)), fs->string);
			free(fs->string);
			fs->string = expanded;
		}
	}
	return (0);
}
