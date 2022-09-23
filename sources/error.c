/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:38:42 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/23 03:37:24 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	error(int messageid)
{
	ft_putstr("error: ");
	ft_putendl(g_error[messageid]);
	return (0);
}
