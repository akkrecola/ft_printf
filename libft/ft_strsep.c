/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:06:18 by elehtora          #+#    #+#             */
/*   Updated: 2022/03/23 11:03:03 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* strsep separates a string into 2 substrings at the first occurence of c
 * (by replacing c with '\0'), and returns a pointer to the 2nd substring.
 *
 * The first parameter p_string is a pointer to the string to be separated.
 * The second parameter is the delimiter character that gets found and nulled.
 * The operation outside of ASCII character set is undefined.
 *
 * Note that no allocation or copying is done - the original string is simply
 * 'cut' at character c, and the two strings occupy the same memory location
 * as before.
*/

char	*ft_strsep(char **p_string, int c)
{
	char	*latter;

	if (!p_string || !(*p_string))
		return (NULL);
	latter = ft_strchr(*p_string, c);
	if (!latter)
		return (NULL);
	else
		*latter = '\0';
	return (latter + 1);
}
