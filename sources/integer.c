/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:39:27 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/23 01:34:53 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Adds a sign for a '+' flag signed conversion.
void	prepend_sign(t_fstring *fs)
{
	char		*sign_prepended_str;

	if (!fs->sign)
	{
		sign_prepended_str = ft_strnew(ft_strlen(fs->string) + 1);
		if (fs->format & F_FORCE_SIGN)
			sign_prepended_str[0] = '+';
		else if (fs->format & F_SPACE_SIGN)
			sign_prepended_str[0] = ' ';
		else if (fs->format & (F_ALT_FORM + C_UOCT))
			sign_prepended_str[0] = '0';
		ft_strcpy(sign_prepended_str + 1, fs->string);
		free(fs->string);
		fs->string = sign_prepended_str;
		fs->len += 1;
	}
}

// Applies a precision greater than the number,
// i.e. left pads the number with 0's.
// Forced signs come only after this, so we only account for negative sign.
static int	pad_integer_precision(t_fstring *fs)
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
		free(fs->string);
		fs->string = str_expanded;
		if (sign)
			fs->string[0] = '-';
		if (fs->len < fs->precision)
			fs->len = fs->precision;
	}
	return (1);
}

void	set_explicit_zero(t_fstring *fs)
{
	if (fs->format & EXPL_PRECISION && fs->precision == 0)
	{
		if (fs->format & C_UOCT && fs->format & F_ALT_FORM)
			fs->string = ft_strdup("0");
		else
			fs->string = ft_strdup("");
	}
	else
		fs->string = ft_strdup("0");
	fs->len = ft_strlen(fs->string);
}

// TODO Length modifiers
int	convert_unsigned_int(t_fstring *fs, va_list *ap)
{
	const int	arg = va_arg(*ap, unsigned int); // TODO Figure out lenconv assignment

	if (arg == 0 && !(fs->format & C_UOCT))
		set_explicit_zero(fs);
	else if (fs->format & (C_UHEX_CAP ^ C_UHEX_LOW)) // FIXME check condition after refactoring
		format_hex(arg, fs);
	else if (fs->format & C_UOCT)
		format_oct(arg, fs);
	else
		fs->string = ft_ltoa_unsigned(arg);
	if (!fs->string)
		return (0);
	fs->len = ft_strlen(fs->string);
	pad_integer_precision(fs);
	if (fs->format & MASK_HEX_PREFIX && !(fs->format & C_UOCT) && arg != 0)
		add_hex_prefix(fs);
	if (fs->field_width > fs->len)
		expand_to_field_width(fs);
	return (2);
}

// TODO Length modifiers
int	convert_signed_int(t_fstring *fs, va_list *ap)
{
	const int	arg = va_arg(*ap, int); // TODO Figure out lenconv assignment

	if (arg == 0)
		set_explicit_zero(fs);
	else
		fs->string = ft_ltoa(arg);
	fs->len = ft_strlen(fs->string);
	if (arg < 0)
		fs->sign = fs->string;
	pad_integer_precision(fs);
	if (fs->format & (F_FORCE_SIGN + F_SPACE_SIGN))
		prepend_sign(fs);
	if (fs->field_width > fs->len)
		expand_to_field_width(fs);
	return (1);
}
