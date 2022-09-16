/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:39:27 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/18 03:54:43 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//FIXME Not aligning right by default?
static void	reformat_sign(t_fstring *fs)
{
	char	*sign;
	char	*sign_prepended_str;

	sign = ft_strchr(fs->string, '-'); // Check if negative
	sign_prepended_str = ft_strnew(ft_strlen(fs->string) + 1);
	if (!sign) // Not negative (or some crazy error where a wild '-' appears)
	{
		if (fs->format & F_FORCE_SIGN)
			sign_prepended_str[0] = '+';
		else if (fs->format & F_SPACE_SIGN)
			sign_prepended_str[0] = ' ';
	}
	else // Number is negative and padded somehow, so realign '-'
	{
		*sign = *(sign - 1); // Clone previous '-' as previous neighbor char
		sign_prepended_str[0] = '-';
	}
	ft_strcpy(sign_prepended_str + 1, fs->string);
	free(fs->string);
	fs->string = sign_prepended_str;
}

// Applies a precision greater than the number, i.e. left pads the number with 0's.
static void	pad_integer_precision(t_fstring *fs)
{
	const size_t	initial_len = ft_strlen(fs->string);
	char			*str_expanded;

	str_expanded = NULL;
	if (initial_len < fs->precision)
	{
		str_expanded = ft_strnew(fs->precision);
		ft_memset(str_expanded, '0', fs->precision);
		ft_memmove(str_expanded + (fs->precision - initial_len),\
				fs->string, initial_len);
		free(fs->string);
		fs->string = str_expanded;
	}
}

// TODO
int	convert_unsigned_int(t_fstring *fs, unsigned long long int arg)
{
	if (fs->format & CMASK_HEX)
		fs->string = format_hex(arg, fs);
	/*else if (fs->format & C_UOCT)*/
		/*fs->string = format_oct(arg, fs);*/
	else
		fs->string = ft_ltoa_unsigned(arg);
	pad_integer_precision(fs);
	fs->field_width = (uint32_t)ft_strlen(fs->string);
	return (2);
}

// TODO
int	convert_signed_int(t_fstring *fs, long long int arg)
{
	// TODO
	if (arg < 0)
		fs->sign = 1;
	fs->string = ft_ltoa(arg);
	pad_integer_precision(fs);
	if (fs->format & (F_FORCE_SIGN + F_SPACE_SIGN))
		reformat_sign(fs);
	/*if (ft_strchr(fs->string, '-') && F_LEFT_PAD)*/
		/*reformat_sign(fs);*/
	// TODO Field width
	if (fs->field_width > ft_strlen(fs->string))
		expand_to_field_width(fs);
	return (1);
}
