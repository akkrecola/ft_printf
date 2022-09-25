/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:38:42 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/25 17:36:16 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Wrapper to call a deconstructer teardown(), then expanding into an erraneous
 * value.
 */
void	error(t_fstring *fs)
{
	teardown(fs);
	exit(EXIT_FAILURE);
}
