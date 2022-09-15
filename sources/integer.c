/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:39:27 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/15 05:44:55 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// TODO
int	convert_unsigned_int(t_fstring *fstring, unsigned long arg)
{
	// TODO
	if (fstring->format & (CMASK_HEX))
		fstring->string = format_hex(arg, fstring);
	/*else if (fstring->format & C_UOCT)*/
		/*format_oct(arg, fstring);*/
	else
		fstring->string = ft_itol_unsigned(arg);
	return (2);
}

// TODO
int	convert_signed_int(t_fstring *fstring, long arg)
{
	// TODO
	fstring = fstring;
	arg = arg;
	return (1);
}
