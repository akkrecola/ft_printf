/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:37:42 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/15 00:08:00 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_string(t_fstring *fstring, const char *arg)
{
	fstring->string = ft_strdup(arg);
	return (3);
}

int	convert_char(t_fstring *fstring, unsigned char arg)
{
	fstring->string = ft_strnew(1);
	*fstring->string = arg;
	return (4);
}
