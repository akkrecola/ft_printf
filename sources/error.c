/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:38:42 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/25 15:18:57 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Wrapper to call a deconstructer teardown(), then expanding into an erraneous
 * value.
 */
int	error(t_fstring *fs)
{
	teardown(fs);
	return (-1);
}
