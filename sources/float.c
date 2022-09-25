/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:16:33 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/25 17:26:30 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define MAX_FRAC_DIGS 256

/* Extracts a fraction of a given (long) double argument and feeds it
 * into a char buffer, returning an allocated string (or NULL on failure).
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

/* Handle floating point rounding notations, e.g. explicit dot '.'
 * on # flag, or special values -infinity, +infinity and NaN (not a number).
 *
 * Reassigns the previously allocated result string fs->string.
 */
static void	determine_double_format(long double arg, t_fstring *fs, \
		char *base, char *fraction)
{
	if (arg == 1.0 / 0.0)
		fs->string = ft_strdup("inf");
	else if (arg == -1.0 / 0.0)
		fs->string = ft_strdup("-inf");
	else if (arg != arg)
		fs->string = ft_strdup("nan");
	else if (fs->precision == 0 && fs->format & EXPL_PRECISION)
	{
		if (fs->format & F_ALT_FORM)
			fs->string = ft_strjoin(base, ".");
		else
			fs->string = ft_strdup(base);
	}
	else
		fs->string = ft_strdjoin(base, ".", fraction);
	if (!fs->string)
		error(fs);
	fs->len = ft_strlen(fs->string);
}

/* Apply formatting to a given double argument, and save the
 * result in the fstring struct variable.
 *
 * Returns -1 on allocation failure, 0 on success.
 */
static void	format_double(t_fstring *fs, long double arg)
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
		error(fs);
	if (arg == 0.0)
		pad_zero_fraction(fs, &fraction);
	determine_double_format(arg, fs, base, fraction);
	ft_strdel(&base);
	ft_strdel(&fraction);
}

/* Cast the variable argument double to long double,
 * if length modifier 'L' has been presented.
 *
 * NOTE: both the double and long double arguments
 * are handled internally as long double, but the cast
 * affects the initial value that the argument assumes.
 */
static double	cast_double(va_list *ap, t_fstring *fs)
{
	if (fs->format & M_DLONG)
		return ((long double)va_arg(*ap, long double));
	else
		return (va_arg(*ap, double));
}

/* Handle an 'f' conversion.
 */
void	convert_double(t_fstring *fs, va_list *ap)
{
	const long double	arg = cast_double(ap, fs);

	format_double(fs, arg);
	fs->len = ft_strlen(fs->string);
	if (arg < 0.0 || arg == -1.0 / 0.0)
		fs->sign = fs->string;
	if (fs->format & (F_FORCE_SIGN | F_SPACE_SIGN)
		&& !ft_strchr("+-n", fs->string[0]))
		prepend_sign(fs);
	if (fs->field_width > fs->len)
		expand_to_field_width(fs);
}
