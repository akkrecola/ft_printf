/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:16:33 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/24 22:25:31 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define MAX_FRAC_DIGS 16
#define DOUBLE_AS_STR_MAXLEN 40

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
 *  a. 
 *
 */

#include <stdio.h>
// TODO TESTING
static long double	round_even(t_fstring *fs, long double arg)
{
	const unsigned long	shift = (long)ft_powl(10, fs->precision);
	const long double	rounded = ft_roundl(arg * shift) / shift;
	const long double	unrounded = ft_truncl(arg * shift) / shift;
	const long double	diff = (arg - unrounded) - (rounded - arg);
	long double			result;

	/*printf("Arg: %Lf\n", arg);*/
	/*printf("Shift: %ld\n", shift);*/
	/*printf("Precision: %u\n", fs->precision);*/
	result = (arg * shift);
	if (arg >= 0.0) // Positive
	{
/*#define DEBUG*/
/*#ifdef DEBUG*/
		/*printf("Positive value: %Lf\n", arg);*/
/*#endif*/
		if (diff > 0.0 || (diff == 0.0 && (long)result % 2 != 0))
			result += 0.5;
	}
	else // Negative
	{
/*#ifdef DEBUG*/
		/*printf("Negative value: %Lf\n", arg);*/
/*#endif*/
		if (diff < 0.0 || (diff == 0.0 && (int)result % 2 != 0))
			result -= 0.5;
	}
	result = ft_truncl(result);
/*#ifdef DEBUG*/
		/*printf("Result in ROUNDING function: %Lf\n", result / shift);*/
/*#endif*/
	return (result /= shift);
}

static int	pad_zero_fraction(uint32_t precision, char	**fraction)
{
	char *padded;

	padded = ft_strnew(precision);
	if (!padded)
		return (0);
	ft_memset(padded, '0', precision);
	free(*fraction);
	*fraction = padded;
	return (1);
}


// TODO make life easier with itof
static int	format_double(t_fstring *fs, long double arg)
{
	char	*base;
	char	*fraction;
	uint8_t	representable;

	if (!(fs->format & EXPL_PRECISION))
		fs->precision = 6;
	if (fs->precision <= MAX_FRAC_DIGS)
		representable = fs->precision;
	else
		representable = MAX_FRAC_DIGS;
	arg = round_even(fs, arg);
	/*printf("Result in FORMAT function: %Lf\n", arg);*/
	base = ft_ltoa((long)arg);
	fraction = ft_ltoa(\
			ft_labs((long)((arg - (long)arg) * ft_exp10(representable))));
	if (!base || !fraction)
		return (0); // FIXME add erroring
	if (arg == 0.0)
		pad_zero_fraction(fs->precision, &fraction); // TODO error handle malloc
	if (fs->format & EXPL_PRECISION && fs->precision == 0)
		fs->string = ft_strdup(base);
	else
		fs->string = ft_strdjoin(base, ".", fraction);
	ft_strdel(&base);
	ft_strdel(&fraction);
	if (!fs->string)
		return (0); // FIXME erroring
	return (1);
}

static long double	cast_double(va_list *ap, t_fstring *fs)
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
	if (arg < 0.0)
		fs->sign = fs->string;
	if (fs->format & (F_FORCE_SIGN | F_SPACE_SIGN) || (fs->sign))
		prepend_sign(fs);
	if (fs->field_width > fs->len)
		expand_to_field_width(fs);
	return (5);
}
