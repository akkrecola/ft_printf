/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:16:33 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/19 05:11:30 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define MAX_FRAC_DIGS 18
#define DOUBLE_AS_STR_MAXLEN 40

/*
 * Joins the double value's parts into a string, and returns the string.
 */
char	*join_double(long base, long fraction, uint32_t precision)
{
	const char	*base_str = ft_ltoa(base);
	const char	*fraction_str = ft_ltoa(fraction);
	char		*result;

	result = NULL;
	if (!(base_str && fraction_str))
		return (NULL);
	if (precision == 0)
		result = ft_strdup(base_str);
	else
		result = ft_strdjoin(base_str, ".", fraction_str); // Delimiter join
	free((void *)base_str);
	free((void *)fraction_str);

	return (result);
}

// Extract the fractional part of a double. The function extracts with the
// 'precision' of 18 fractional digits, not considering whether they are
// significant or not. A precision calculation must be done separately.
long	extract_fraction(double arg)
{
	unsigned int	i;

	i = 0;
	while (i++ < MAX_FRAC_DIGS)
		arg *= 10;
	return ((long)arg);
}

// Rounds to the nearest EVEN integer.
// TODO Extend rounding to integer part
// FIXME NOT WORKING, extend comparison if consecutive 5's
static long	bankers_round(long fraction)
{
	if (fraction % 10 == 5)
	{
		if ((((fraction - (fraction % 10)) / 10) % 10) % 2) // odd == true
			return ((fraction - (fraction % 10)) / 10 + 1); // ceil()
		else
			return ((fraction - (fraction % 10)) / 10); // floor()
	}
	else
		return ((fraction - (fraction % 10)) / 10);
}

// Return a string representation of a given double.
// TODO Remove decimal point on explicit 0 precision
char	*format_double(t_fstring *fstring, double arg)
{
	long	base;
	long	fraction;
	char	*joined; // The unformatted double value as string

	if (!(fstring->format & EXPL_PRECISION))
		fstring->precision = DEFAULT_FLOAT_PRECISION; // Default fo
	// Cut off fraction with integer division
	base = arg / 1;
	fraction = extract_fraction(arg - base);
	// Leaving a rounding digit in (the -1 at the end)
	fraction /= ft_pow(10, MAX_FRAC_DIGS - fstring->precision - 1);
	// Bankers' Rounding
	if (fraction >= 10)
		fraction = bankers_round(fraction);
	else
		base += 1;
	joined = join_double(base, fraction, fstring->precision);
	(void)(fstring); // FIXME suppressing error

	return (joined);
}

int	convert_double(t_fstring *fstring, double arg)
{
	fstring->string = format_double(fstring, arg);
	return (5);
}
