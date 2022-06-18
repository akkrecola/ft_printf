/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:20:36 by elehtora          #+#    #+#             */
/*   Updated: 2022/02/17 06:17:26 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** Outputs n characters of *s memory to stdout.
*/

void	ft_putmem(char *s, size_t n)
{
	write(1, s, n);
}
