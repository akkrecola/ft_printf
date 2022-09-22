/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:54:27 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/22 23:23:21 by elehtora         ###   ########.fr       */
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

void	reset_sign(t_fstring *fs)
{
	char	*p_sign;
	char	sign_char;

	p_sign = ft_strpbrk(fs->string, "+-o");
	if (p_sign && p_sign != fs->string && fs->format & F_ZERO_PAD)
	{
		sign_char = *p_sign;
		*p_sign = *(p_sign - 1);
		fs->string[0] = sign_char;
	}
}

static void	expand_zeros(t_fstring *fs, char *expanded)
{
	ft_memset(expanded, '0', fs->field_width);
	if (fs->format & MASK_HEX_PREFIX \
			&& (fs->string[1] == 'X' || fs->string[1] == 'x'))
	{
		ft_memmove(expanded, fs->string, 2);
		ft_memset(fs->string, '0', 2);
	}
}

int	expand_to_field_width(t_fstring *fs)
{
	char	*expanded;

	expanded = ft_strnew(fs->field_width);
	if (!expanded)
		return (-1);
	if (fs->format & F_ZERO_PAD)
		expand_zeros(fs, expanded);
	else
		ft_memset(expanded, ' ', fs->field_width);
	if (fs->format & F_LEFT_ALIGN)
		align_left(fs, expanded);
	else
	{
		ft_memmove(expanded + (fs->field_width - fs->len), \
				fs->string, fs->len);
		free(fs->string);
		fs->string = expanded;
		reset_sign(fs);
	}
	fs->len = fs->field_width;
	return (0);
}
