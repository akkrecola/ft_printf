/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:16:33 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/25 12:16:52 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define MAX_FRAC_DIGS 256

/*
 * Floatmap:
 * PREPARATION
 * 1. Cast to long double
 * ROUNDING
 * 2. Realign with precision by multiplying with pow(10, fs->precision)
 * 3. Create 1) rounded (away from zero) and 2) unrounded (truncated)
 *    variables, and compare their distance from the original 'arg'
 * 4. Round up if the difference towards the original value is GREATER in
 *    the UNROUNDED than the ROUNDED.
 *    Also round up if DIFFERENCE IS EXACTLY 0 (distances are equal == fraction
 *    is exactly 0.5).
 * 5. Return the value with correct rounding applied.
 * FTOA - float (long double) to int
 * 6. Get the precision shift value (long double shift = pow(10, precision))
 * 7. Extract the integral part (long base = (long)arg)
 * 8. Extract the fractional part
 *
 */

static char	*extract_fraction(t_fstring *fs, long double arg)
{
	char		buf[MAX_FRAC_DIGS + 1];
	uint32_t	i;

	ft_bzero(buf, MAX_FRAC_DIGS);
	i = 0;
	if (arg < 0.0)
		arg = ft_fabsl(arg);
	while (i < fs->precision && i < MAX_FRAC_DIGS)
	{
		buf[i] = (uint64_t)(arg * 10) % 10 + '0';
		arg *= 10;
		arg -= ft_truncl(arg);
		i++;
	}
	return (ft_strdup(buf));
}

static void	determine_double_format(long double arg, t_fstring *fs, \
		char *base, char *fraction)
{
	if (arg == 1.0 / 0.0)
		fs->string = ft_strdup("inf");
	else if (arg == -1.0 / 0.0)
		fs->string = ft_strdup("-inf");
	else if (arg != arg)
		fs->string = ft_strdup("nan");
	else if (fs->format & EXPL_PRECISION && fs->precision == 0)
		fs->string = ft_strdup(base);
	else
		fs->string = ft_strdjoin(base, ".", fraction);
}

static int	format_double(t_fstring *fs, long double arg)
{
	char	*base;
	char	*fraction;

	if (!(fs->format & EXPL_PRECISION))
		fs->precision = 6;
	arg = round_even(fs, arg);
	base = ft_ltoa((long)arg);
	if ((arg < 0.0 && ft_strequ(base, "0")) || (1 / arg == -1 / 0.0))
		base = ft_freejoin("-", base, 'b');
	fraction = extract_fraction(fs, arg);
	if (!base || !fraction)
		return (0);
	if (arg == 0.0)
		pad_zero_fraction(fs->precision, &fraction);
	determine_double_format(arg, fs, base, fraction);
	ft_strdel(&base);
	ft_strdel(&fraction);
	if (!fs->string)
		return (0);
	return (1);
}

static double	cast_double(va_list *ap, t_fstring *fs)
{
	if (fs->format & M_DLONG)
		return ((long double)va_arg(*ap, long double));
	else
		return (va_arg(*ap, double));
}

int	convert_double(t_fstring *fs, va_list *ap)
{
	const long double	arg = cast_double(ap, fs);

	if (!format_double(fs, arg) || !fs->string)
		return (0);
	fs->len = ft_strlen(fs->string);
	if (arg < 0.0 || arg == -1.0 / 0.0)
		fs->sign = fs->string;
	if (fs->format & (F_FORCE_SIGN | F_SPACE_SIGN)
		&& !ft_strchr("+-n", fs->string[0]))
		prepend_sign(fs);
	if (fs->field_width > fs->len)
		expand_to_field_width(fs);
	return (5);
}
