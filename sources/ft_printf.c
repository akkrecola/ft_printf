/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:10:19 by elehtora          #+#    #+#             */
/*   Updated: 2022/06/18 17:12:22 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char restrict *format, ...)
{
	va_list ap;

	get_directives();		// parse format string before variadic stuff
	va_start(ap, format);
	va_end(ap);
}
