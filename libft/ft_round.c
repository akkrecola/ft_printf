/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:10:19 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/24 18:21:44 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_roundl(long double x)
{
	if (x < 0.0)
		return (ft_truncl(x - 0.5));
	else
		return (ft_truncl(x + 0.5));
}
