/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:47:20 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/14 17:08:15 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
 * Gets the length of a string array (array of char *). The counting is done
 * until a NULL pointer is found, therefore the array MUST be NULL terminated.
 *
 * Returns the amount of strings found.
 */
int	ft_strarrlen(char **str_array)
{
	int	count;

	count = 0;
	while (*str_array != NULL)
	{
		count++;
		str_array++;
	}
	return (count);
}
