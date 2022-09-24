/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:16:33 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/24 14:01:13 by elehtora         ###   ########.fr       */
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
/*static double	_round(double d)*/
/*{*/
	
/*}*/

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
	i = 0;
	while (i < fs->precision)
	{
		arg = arg * 10; // Bring first decimal as base
		current = (int)arg + '0';
		ft_charappend(fraction, (char)current); // Append to fraction string
		arg = arg - (int)arg; // floor()
		i++;
	}
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

/*static double	cast_double(va_list *ap, t_fstring *fs)*/
/*{*/
	
/*}*/

int	convert_double(t_fstring *fs, va_list *ap)
{
	const double	arg = (const double)va_arg(*ap, double); // TODO turn into casting function

	fs->string = format_double(fs, arg);
	if (!fs->string)
		return (0);
	fs->len = ft_strlen(fs->string);
	if (arg < 0.0)
		fs->sign = fs->string;
	if (fs->format & (F_FORCE_SIGN + F_SPACE_SIGN))
		prepend_sign(fs);
	if (fs->field_width > fs->len)
		expand_to_field_width(fs);
	return (5);
}
