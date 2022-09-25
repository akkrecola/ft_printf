/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numerical_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 05:25:03 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/25 10:28:02 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Adds a sign for a '+' flag signed conversion.
void	prepend_sign(t_fstring *fs)
{
	char		*sign_prepended_str;

	sign_prepended_str = ft_strnew(ft_strlen(fs->string) + 1);
	if (fs->format & F_FORCE_SIGN && !fs->sign)
		sign_prepended_str[0] = '+';
	else if (fs->format & F_SPACE_SIGN)
		sign_prepended_str[0] = ' ';
	else if ((fs->format & (CMASK | F_ALT_FORM)) == (F_ALT_FORM | C_UOCT))
		sign_prepended_str[0] = '0';
	else if ((fs->format & (C_FLOAT)) && fs->sign)
		sign_prepended_str[0] = '-';
	ft_strcpy(sign_prepended_str + 1, fs->string);
	ft_strdel(&fs->string);
	fs->string = sign_prepended_str;
	fs->len += 1;
}

// Applies a precision greater than the number,
// i.e. left pads the number with 0's.
// Forced signs come only after this, so we only account for negative sign.
int	pad_integer_precision(t_fstring *fs)
{
	char			*str_expanded;
	uint8_t			sign;

	sign = 0;
	if (fs->sign)
		sign = 1;
	if (fs->precision > fs->len - sign)
	{
		fs->precision += sign;
		if (sign)
			fs->string[0] = '0';
		str_expanded = ft_strnew(fs->precision);
		if (!str_expanded)
			return (0);
		ft_memset(str_expanded, '0', fs->precision);
		ft_memmove(str_expanded + (fs->precision - fs->len), \
				fs->string, fs->len);
		ft_strdel(&fs->string);
		fs->string = str_expanded;
		if (sign)
			fs->string[0] = '-';
		if (fs->len < fs->precision)
			fs->len = fs->precision;
	}
	return (1);
}
