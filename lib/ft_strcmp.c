/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 02:24:19 by elehtora          #+#    #+#             */
/*   Updated: 2022/02/21 13:08:33 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Need for cast in while condition?
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	while ((unsigned char) *s1 == (unsigned char) *s2 && (*s1 && *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}
