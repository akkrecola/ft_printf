/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:49:22 by elehtora          #+#    #+#             */
/*   Updated: 2022/02/22 21:05:54 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_iswhite() returns non-zero (1) if c is an ASCII whitespace character, 0
** otherwise.
*/

int	ft_iswhite(char c)
{
	return ((9 <= c && c <= 13) || c == 32);
}
