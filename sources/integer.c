/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:39:27 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/25 02:55:24 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Adds a sign for a '+' flag signed conversion.
void	prepend_sign(t_fstring *fs)
{
	char		*sign_prepended_str;

	sign_prepended_str = ft_strnew(ft_strlen(fs->string) + 1);
	if (fs->format & F_FORCE_SIGN)
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

// Applies a precision greater than the number,
// i.e. left pads the number with 0's.
// Forced signs come only after this, so we only account for negative sign.
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

void	set_explicit_zero(t_fstring *fs)
{
	if (fs->format & EXPL_PRECISION && fs->precision == 0)
	{
		if ((fs->format & (CMASK | F_ALT_FORM)) == (C_UOCT | F_ALT_FORM))
			fs->string = ft_strdup("0");
		else
			fs->string = ft_strdup("");
	}
	else
		fs->string = ft_strdup("0");
	fs->len = ft_strlen(fs->string);
}

static unsigned long long	cast_unsigned(t_fstring *fs, va_list *ap)
{
	if (fs->format & M_CHAR)
		return ((unsigned char)va_arg(*ap, unsigned int));
	if (fs->format & M_SHRT)
		return ((unsigned short)va_arg(*ap, unsigned int));
	if (fs->format & M_LONG)
		return ((unsigned long)va_arg(*ap, unsigned long int));
	if (fs->format & M_LLONG)
		return ((unsigned long long)va_arg(*ap, unsigned long long int));
	return (va_arg(*ap, unsigned int));
}

// TODO Length modifiers
int	convert_unsigned_int(t_fstring *fs, va_list *ap)
{
	const unsigned long long arg = cast_unsigned(fs, ap); // cast_unsigned(fs, ap); // TODO Figure out lenconv assignment

	if (arg == 0 && ((fs->format & CMASK) != C_UOCT))
		set_explicit_zero(fs);
	else if (fs->format & CMASK & HEX_MASK)
		format_hex(arg, fs);
	else if ((fs->format & CMASK) == C_UOCT)
		format_oct(arg, fs);
	else
		fs->string = ft_ltoa_unsigned(arg);
	if (!fs->string)
		return (0);
	fs->len = ft_strlen(fs->string);
	pad_integer_precision(fs);
	if ((fs->format & MASK_HEX_PREFIX) \
			&& (fs->format & CMASK & HEX_MASK) \
			&& arg != 0)
		add_hex_prefix(fs);
	if (fs->field_width > fs->len)
		expand_to_field_width(fs);
	return (2);
}

static long long	cast_signed(t_fstring *fs, va_list *ap)
{
	if (fs->format & M_CHAR)
		return ((char)va_arg(*ap, int));
	if (fs->format & M_SHRT)
		return ((short)va_arg(*ap, int));
	if (fs->format & M_LONG)
		return ((long)va_arg(*ap, long));
	if (fs->format & M_LLONG)
		return ((long long)va_arg(*ap, long long));
	return (va_arg(*ap, int));
}

// TODO Length modifiers
int	convert_signed_int(t_fstring *fs, va_list *ap)
{
	const long long	arg = cast_signed(fs, ap);

	if (arg == 0)
		set_explicit_zero(fs);
	else
		fs->string = ft_ltoa(arg);
	fs->len = ft_strlen(fs->string);
	if (arg < 0)
		fs->sign = fs->string;
	pad_integer_precision(fs);
	if (fs->format & (F_FORCE_SIGN + F_SPACE_SIGN) && !fs->sign)
		prepend_sign(fs);
	if (fs->field_width > fs->len)
		expand_to_field_width(fs);
	return (1);
}
