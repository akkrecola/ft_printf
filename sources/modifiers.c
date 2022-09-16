/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 01:18:59 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/18 04:49:19 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint32_t	set_type(const char *type)
{
	if (*type == 'd' || *type == 'i')
		return (C_SDEC);
	else if (*type == 'o')
		return (C_UOCT);
	else if (*type == 'u')
		return (C_UDEC);
	else if (*type == 'x')
		return (C_UHEX_LOW);
	else if (*type == 'X')
		return (C_UHEX_CAP);
	else if (*type == 'f')
		return (C_FLOAT);
	else if (*type == 'c')
		return (C_CHAR);
	else if (*type == 's')
		return (C_STRING);
	else if (*type == 's')
		return (C_STRING);
	else if (*type == 'p')
		return (C_VOIDHEX);
	else if (*type == '%')
		return (C_INIT);
	return (FORMAT_ERROR);
}

const char	*set_flags(const char *iterator, t_fstring *fs)
{
	const char	*first_flag = ft_strpbrk(iterator, FLAGS);
	const char	*flagset = ft_strgetset(\
			iterator, FLAGS, FLAG_DELIMS, fs->type - iterator);

	if (!first_flag || !flagset) // TODO Check if flagset gets freed in strgetset on NULL return
		return (iterator);
	// Setting formatting bitmap
	if (ft_strchr(flagset, '#'))
		fs->format ^= F_ALT_FORM;
	if (ft_strchr(flagset, '-'))
		fs->format ^= F_LEFT_ALIGN;
	if (ft_strchr(flagset, '0') && !(fs->format & F_LEFT_ALIGN))
		fs->format ^= F_ZERO_PAD;
	if (ft_strchr(flagset, '+'))
		fs->format ^= F_FORCE_SIGN;
	if (ft_strchr(flagset, ' ') && !(fs->format & F_FORCE_SIGN))
		fs->format ^= F_SPACE_SIGN;
	// FIXME Check if needed
	if (fs->format & MASK_FLAGS)
		fs->format ^= EXPL_FLAGS;
	free((char *)flagset);
	return (iterator); // FIXME Return a usable stepping value
}

// TODO
#define FWIDTH_MAXCHARS 10
const char	*set_field_width(const char *iterator, t_fstring *fs)
{
	const char	*delimiter = ft_strpbrk(iterator, FWIDTH_DELIMS);
	char		buf[FWIDTH_MAXCHARS]; // INT_MAX is 10 in length
	uint8_t		i;

	ft_bzero(&buf[0], FWIDTH_MAXCHARS);
	iterator += 1; // Clear the possible '0' flag at '*iterator'
	i = 0;
	while (ft_isdigit(*iterator) && iterator != delimiter)
		buf[i++] = *iterator++;
	fs->field_width = ft_atoi(&buf[0]);
	return (iterator - i);
}

#define PRECISION_BUF_SIZE 10 // TODO Check if this can be overflown
// Sets the precision for a format string.
// Returns a pointer to character after the last digit.
const char	*set_precision(const char *iterator, t_fstring *fs)
{
	char		*current;
	char		precision_str[PRECISION_BUF_SIZE];
	uint64_t	precision_val;
	uint32_t	i;

	current = ft_memchr(iterator, '.', fs->type - iterator);
	if (!current || *(current + 1) == '-') // No dot or negative input
		return (iterator);
	else
		fs->format ^= EXPL_PRECISION; // FIXME Check the XOR assignment
	ft_bzero(&precision_str[0], PRECISION_BUF_SIZE);
	i = 1;
	while (ft_isdigit(current[i]) && i < PRECISION_BUF_SIZE)
	{
		precision_str[i - 1] = current[i];
		i++;
	}
	precision_val = (uint64_t)ft_atoi(&precision_str[0]); // FIXME Need to (create and) use atol()
	if (precision_val < MAX_PRECISION)
		fs->precision = precision_val;
	return (&current[i]);
}
