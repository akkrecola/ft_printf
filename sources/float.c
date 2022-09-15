/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:16:33 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/15 21:45:37 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define MAX_FRACTIONAL_DIGITS 18
#define DOUBLE_AS_STR_MAXLEN 40

/*
 * Joins the double value's parts into a string, and returns the string.
 */
char	*join_double(long base, long fraction)
{
	const char	*base_str = ft_ltoa(base);
	const char	*fraction_str = ft_ltoa(fraction);
	char		*result;

	if (base_str && fraction_str)
		result = ft_strdjoin(base_str, ".", fraction_str); // Delimiter join
	free((void *)base_str);
	free((void *)fraction_str);

	return (result);
}

// Extract the fractional part of a double. The function extracts with the
// 'precision' of 18 fractional digits, not considering whether they are
// significant or not. A precision calculation must be done separately.
#include <stdio.h>
long	extract_fraction(double arg)
{
	unsigned	i;

	// printf("arg: %f\n", arg);
	i = 0;
	while (i++ < MAX_FRACTIONAL_DIGITS) // || arg == 0.0
		arg *= 10;
	return ((long)arg);
}

// Return a string representation of a given double.
char	*format_double(t_fstring *fstring, double arg)
{
	long	base;
	long	fraction;
	char	*joined; // The unformatted double value as string

	// Cut off fraction with integer division
	base = arg / 1;
	// printf("Base: %ld\n", base);
	fraction = extract_fraction(arg - base);
	joined = join_double(base, fraction);
	fstring = fstring; // TODO placeholder

	return (joined);
}

int	convert_double(t_fstring *fstring, double arg)
{
	fstring->string = format_double(fstring, arg);
	return (5);
}
