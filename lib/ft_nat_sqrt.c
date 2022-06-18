/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:37:26 by elehtora          #+#    #+#             */
/*   Updated: 2022/06/10 18:48:43 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Square root for natural numbers*/
size_t	ft_nat_sqrt(unsigned int n)
{
	size_t	root;

	root = 0;
	while (root * root < n)
		root++;
	return (root);
}
