/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:08:13 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/23 02:26:25 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCH_H
# define DISPATCH_H

# include "ft_printf.h"
# define CONVERSIONS 10

// Dispatch table for conversion functions. The functions should take as
// parameters (t_fstring *fs, va_list *ap) and return t_fstring *.
typedef int convert(t_fstring *fs, va_list *ap);

// Global dispatch table. Duplicates cater to the indexing of fs->format (see:
// ft_printf.h)
convert	*g_convert[CONVERSIONS] =
{
	convert_signed_int,
	convert_unsigned_int,
	convert_unsigned_int,
	convert_unsigned_int,
	convert_unsigned_int,
	convert_double,
	convert_char,
	convert_string,
	convert_void,
	give_percent,
};

#endif
