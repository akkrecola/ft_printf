/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:54:27 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/25 17:09:34 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Seeks a sign character misaligned in a result string, resetting it to the
 * front of the non-whitespace result string.
 */
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

/* (Re)aligns a right-justified (default) strign to the border of the field,
 * if sufficient space is available.
 *
 * Returns 0 on success, -1 on provided NULL pointer.
 */
void	align_left(t_fstring *fs, char *left_adjusted_str)
{
	if (fs->field_width > fs->len)
	{
		ft_memmove(left_adjusted_str, fs->string, fs->len);
		ft_strdel(&fs->string);
		fs->string = left_adjusted_str;
	}
}

/* Helper to expand_to_field_width: expands to field width by
 * writing zero padding instead of default <space>.
 */
static void	expand_zeros(t_fstring *fs, char *expanded)
{
	ft_memset(expanded, '0', fs->field_width);
	if (fs->format & (F_SPACE_SIGN | F_ZERO_PAD) && fs->string[0] == ' ')
	{
		expanded[0] = ' ';
		fs->string[0] = '0';
	}
	if (fs->format & MASK_HEX_PREFIX \
			&& (fs->string[1] == 'X' || fs->string[1] == 'x'))
	{
		ft_memmove(expanded, fs->string, 2);
		ft_memset(fs->string, '0', 2);
	}
}

/* Expand the area of writing to the field width set in
 * format struct 'fs'. Different alignment and notation 
 * options apply based on gathered formatting data.
 */
void	expand_to_field_width(t_fstring *fs)
{
	char	*expanded;

	expanded = ft_strnew(fs->field_width);
	if (!expanded)
		error(fs);
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
		ft_strdel(&fs->string);
		fs->string = expanded;
		reset_sign(fs);
	}
	fs->len = fs->field_width;
}
