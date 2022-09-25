/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 01:18:59 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/25 15:07:40 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define FWIDTH_MAXCHARS 10
#define PRECISION_BUF_SIZE 10

/* Matches a type/conversion specifier at the end of a format string and
 * sets a corresponding bitflag.
 */
uint16_t	set_type(const char *type)
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

/* Sets flags from set "-+ #0" to the proper bits, with certain rules
 * (see: man 3 printf; flags) in case of overlaps.
 */
void	set_flags(const char *init, const char *delim, t_fstring *fs)
{
	const char	*flagset = ft_strgetset(init, FLAGS, "", delim - init);

	if (!flagset)
		return ;
	if (ft_strchr(flagset, '#'))
		fs->format ^= F_ALT_FORM;
	if (ft_strchr(flagset, '-'))
		fs->format ^= F_LEFT_ALIGN;
	if (ft_strchr(flagset, '0') \
		&& !(fs->format & (F_LEFT_ALIGN))
		&& !((fs->format & EXPL_PRECISION)
			&& ft_strchr(NUM_TYPES, *fs->type)))
		fs->format ^= F_ZERO_PAD;
	if (ft_strchr(flagset, '+'))
		fs->format ^= F_FORCE_SIGN;
	if (ft_strchr(flagset, ' ') && !(fs->format & F_FORCE_SIGN))
		fs->format ^= F_SPACE_SIGN;
	free((char *)flagset);
}

/* Sets the maximum field width of a format string, limited by INT_MAX.
 * Field width never truncates a value.
 * Returns a pointer to the character after the last digit of the field width
 * string.
 */
const char	*set_field_width(const char *init, const char *delim, t_fstring *fs)
{
	const char	*iterator = ft_strpbrk(init, FWIDTH_DIGITS);
	char		buf[FWIDTH_MAXCHARS];
	uint8_t		i;

	if (!iterator || iterator >= delim)
		return ((char *)delim);
	ft_bzero(&buf[0], FWIDTH_MAXCHARS);
	i = 0;
	while (ft_isdigit(*iterator) && iterator != delim)
		buf[i++] = *iterator++;
	if (buf[0] != 0)
		fs->field_width = ft_atoi(&buf[0]);
	return ((char *)iterator - i);
}

/* Sets the precision for a format string.
 * Returns a pointer to the precision specifying dot before the first digit.
 */
const char	*set_precision(const char *init, const char *delim, t_fstring *fs)
{
	char		*dot;
	char		precision_str[PRECISION_BUF_SIZE];
	uint32_t	precision_val;
	uint8_t		i;

	dot = ft_memchr(init, '.', delim - init);
	if (!dot || *(dot + 1) == '-')
		return ((char *)delim);
	fs->format ^= EXPL_PRECISION;
	ft_bzero(&precision_str[0], PRECISION_BUF_SIZE);
	i = 1;
	while (ft_isdigit(dot[i]) && i < PRECISION_BUF_SIZE)
	{
		precision_str[i - 1] = dot[i];
		i++;
	}
	precision_val = ft_atoi(&precision_str[0]);
	if (precision_val < MAX_PRECISION)
		fs->precision = precision_val;
	return (dot);
}

/* Seeks and sets the length modifiers hh, h, l, ll and L; char, short,
 * long, long long and long double, respectively, in a bit field.
 * Returns a pointer to the first modifier character, or NULL,
 * if no length modifer was found.
 */
const char	*set_length_modifier(const char *init, \
		const char *delim, t_fstring *fs)
{
	const char	*mod = ft_strpbrk(init, LENMODS);

	if (!mod || !(mod + 1 == delim || mod + 2 == delim))
		return (delim);
	if (mod[0] == 'h')
	{
		if (mod[1] == 'h')
			fs->format |= M_CHAR;
		else
			fs->format |= M_SHRT;
	}
	else if (mod[0] == 'l')
	{
		if (mod[1] == 'l')
			fs->format |= M_LLONG;
		else
			fs->format |= M_LONG;
	}
	else if (mod[0] == 'L')
		fs->format |= M_DLONG;
	return (mod);
}
