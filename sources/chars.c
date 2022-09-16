/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:37:42 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/18 04:22:39 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_string(t_fstring *fs, const char *arg)
{
	fs->string = ft_strdup(arg);
	return (3);
}

int	convert_char(t_fstring *fs, unsigned char arg)
{
	fs->string = ft_strnew(1);
	*fs->string = arg;
	return (4);
}

int	give_percent(t_fstring *fs)
{
	fs->string = ft_strdup("%");
	return (7);
}
