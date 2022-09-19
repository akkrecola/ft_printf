/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:16:33 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/19 07:43:24 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define MAX_FRAC_DIGS 18
#define DOUBLE_AS_STR_MAXLEN 40

/*
 * Joins the double value's parts into a string, and returns the string.
 */
char	*join_double(long base, long fraction, t_fstring *fs)
{
	const char	*base_str = ft_ltoa(base);
	char		*fraction_str;
	char		*result;

	if (ft_count_digs(fraction) < fs->precision)
	{
		fraction_str = ft_strnew(fs->precision);
		if (!fraction_str)
			return (NULL);
		ft_memset(fraction_str, '0', fs->precision);
	}
	else
		fraction_str = ft_ltoa(fraction);
	result = NULL;
	if (!(base_str && fraction_str))
		return (NULL);
	if (fs->precision == 0)
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
static long	extract_fraction(double arg, uint32_t precision)
{
	unsigned int	i;

	if (arg < 0)
		arg *= -1.0f;
	i = 0;
	while (i++ < precision)
		arg *= 10;
#ifdef DEBUG
	ft_putstr("FRACTION: ");
	ft_putnbr((long)arg);
	ft_putchar('\n');
#endif
	return ((long)arg);
}

// Rounds to the nearest EVEN integer.
// TODO Extend rounding to integer part
// FIXME NOT WORKING, extend comparison if consecutive 5's
/*static long	bankers(long fraction, uint32_t precision)*/
/*{*/
/*}*/

// Return a string representation of a given double.
// TODO Remove decimal point on explicit 0 precision
char	*format_double(t_fstring *fs, double arg)
{
	long	base;
	long	fraction;
	char	*joined; // The unformatted double value as string

	if (!(fs->format & EXPL_PRECISION))
		fs->precision = DEFAULT_FLOAT_PRECISION; // Default fo
	// Cut off fraction with integer division
	base = arg / 1;
	fraction = extract_fraction(arg - base, fs->precision);
	// Leaving a rounding digit in (the -1 at the end)
	//fraction /= ft_pow(10, MAX_FRAC_DIGS - fs->precision - 1);
	joined = join_double(base, fraction, fs);
	if (!joined)
		return (NULL);
	(void)(fs); // FIXME suppressing error

	return (joined);
}

int	convert_double(t_fstring *fs, long double arg)
{
	fs->string = format_double(fs, arg);
	if (!fs->string)
		return (0);
	if (fs->field_width > ft_strlen(fs->string))
		expand_to_field_width(fs);
	return (5);
}
