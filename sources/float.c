/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:16:33 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/20 02:17:25 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define MAX_FRAC_DIGS 18
#define DOUBLE_AS_STR_MAXLEN 40

/*
 * Joins the double value's parts into a string, and returns the string.
 */
char	*join_double(const char *base, const char *fraction, t_fstring *fs)
{
	char		*result;

	(void)fs;
	result = NULL;
	if (!(base && fraction))
		return (NULL);
	if (fs->precision == 0)
		result = ft_strdup(base);
	else
		result = ft_strdjoin(base, ".", fraction); // Delimiter join
	free((void *)base);
	free((void *)fraction);
	return (result);
}

// Round to nearest
void	round_fraction(char *fraction, double arg, t_fstring *fs)
{
	uint8_t	i;

	(void)arg;
	ft_printf("Char at the end of fraction:\t%c\n", fraction[fs->precision - 1]);
	i = fs->precision;
	while (--i)
	{
		arg = arg * 10;
		//ft_printf("Argument in loop: %d\n", (int)arg);
		arg = arg - (arg / 1.0);
	}
	ft_printf("\n");
}

// Extract the fractional part of a double. The function extracts with the
// 'precision' of 18 fractional digits, not considering whether they are
// significant or not. A precision calculation must be done separately.
static char	*extract_fraction(t_fstring *fs, double arg)
{
	char		*fraction;
	int			current;
	uint32_t	i;

	if (arg < 0)
		arg *= -1.0;
	fraction = ft_strnew(fs->precision);
	if (!fraction)
		return (fraction);
	arg = arg - (long)arg;
#include <stdio.h>
	printf("Argument OUTSIDE loop: %f\n", arg);
	i = 0;
	while (i < fs->precision)
	{
		arg = arg * 10; // Bring first decimal as base
		current = (int)arg + '0';
		ft_charappend(fraction, (char)current); // Append to fraction string
		arg = arg - (int)arg; // floor()
		i++;
	}
	ft_printf("Fraction BEFORE rounding:\t%s\n", fraction);
	/*round_fraction(fraction, arg, fs);*/
	ft_printf("Fraction AFTER rounding:\t%s\n", fraction);
	return (fraction);
}

// Return a string representation of a given double.
// TODO Remove decimal point on explicit 0 precision
char	*format_double(t_fstring *fs, double arg)
{
	const char	*base = ft_ltoa((long)arg);
	char		*fraction;

	if (!(fs->format & EXPL_PRECISION))
		fs->precision = DEFAULT_FLOAT_PRECISION;
	fraction = extract_fraction(fs, arg);
	return (join_double(base, fraction, fs));
}

int	convert_double(t_fstring *fs, double arg)
{
	fs->string = format_double(fs, arg);
	if (arg < 0.0)
		fs->sign = fs->string;
	if (!fs->string)
		return (0);
	if (fs->format & (F_FORCE_SIGN + F_SPACE_SIGN))
		prepend_sign(fs);
	if (fs->field_width > ft_strlen(fs->string))
		expand_to_field_width(fs);
	return (5);
}
