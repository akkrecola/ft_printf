/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:20:05 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/19 03:43:45 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#define HEX_DIVIDEND 16
#define HEX_BUFSIZE 32

// Adds the correct hex prefix to a string
static void	add_hex_prefix(char *buf, char type)
{
	char	prefix[2];

	prefix[0] = '0';
	if (type == 'X')
		prefix[1] = 'X';
	else
		prefix[1] = 'x';
	ft_strncpy(buf, &prefix[0], 2);
}

static char	*build_hex(unsigned long arg, char *buf, int is_upper)
{
	char	current;
	int		remainder;
	
	current = 0;
	remainder = 0;
	while (arg > 0)
	{
		remainder = arg % HEX_DIVIDEND;
		if (remainder >= 10)
		{
			if (is_upper)
				current = remainder + 55; // 10 -> A
			else
				current = remainder + 87; // 10 -> a
		}
		else
			current = remainder + '0'; // 9 -> 7
		ft_charappend(buf, current);
		arg /= HEX_DIVIDEND; // NOTE: integer division
	}
	return (ft_strrev(buf));
}

// Convert a clean integer value to a hex format string.
// First one to call on hex conversions (before precision and fwidth)
char	*format_hex(unsigned long long arg, t_fstring *fstring)
{
	char	buf[HEX_BUFSIZE]; // max hex format length is about 16 bytes
	char	*rev_base;

	ft_bzero(buf, HEX_BUFSIZE);
	if (fstring->format & MASK_HEX_PREFIX)
		add_hex_prefix(&buf[0], *fstring->type);
	rev_base = build_hex(arg, &buf[2], (fstring->format & C_UHEX_CAP));
	ft_strcpy(&buf[2], rev_base);
	free(rev_base);
	return (ft_strdup(&buf[0]));
}

// TODO NOT WORKING
int	convert_void(t_fstring *fstring, void *arg)
{
	const long long	address = (long long)*((long long *)arg);

	printf("\nAddress:\n\tOwn:\t0x%llx\n\tActual:\t%p\n", address, arg);
	fstring->string = format_hex(address, fstring);
	ft_putstr(fstring->string);
	printf("\nAddress:\n\tOwn:\t0x%llx\n\tActual:\t%p\n", address, arg);
	return (6);
}
