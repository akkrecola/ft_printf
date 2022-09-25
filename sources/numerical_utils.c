/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numerical_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 05:25:03 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/25 16:11:38 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Pads a specified fraction string (extracted from an (long) double argument)
 * with zeroes on the right. This is needed when a literal 0 fractional part
 * is truncated to .0 ending, but the lesser zero digits need to be represented.
 */
int	pad_zero_fraction(uint32_t precision, char **fraction)
{
	char	*padded;

	padded = ft_strnew(precision);
	if (!padded)
		return (0);
	ft_memset(padded, '0', precision);
	free(*fraction);
	*fraction = padded;
	return (1);
}

/* Banker's rounding function. Rounds to nearest and ties (remainder
 * EXACTLY 0.5) to EVEN. (0.5 -> 0, 1.5 -> 2).
 */
long double	round_even(t_fstring *fs, long double arg)
{
	const unsigned long	shift = ft_exp10(fs->precision);
	const long double	rounded = ft_roundl(arg * shift) / shift;
	const long double	unrounded = ft_truncl(arg * shift) / shift;
	const long double	diff = (arg - unrounded) - (rounded - arg);

	if (arg >= 0.0)
	{
		if (diff > 0.0 || (diff == 0.0 && (long)(arg * shift) % 2 != 0))
			arg += (0.5 / shift);
	}
	else
	{
		if (diff < 0.0 || (diff == 0.0 && (long)(arg * shift) % 2 != 0))
			arg -= (0.5 / shift);
	}
	return (arg);
}

 /* Prepends a sign based on formatting information, often due to + flag.
  */
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

/* Applies a precision greater than the numbers total digits (+ sign),
 * i.e. left pads the number with 0's.
 */
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
