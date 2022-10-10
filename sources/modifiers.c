/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 01:18:59 by elehtora          #+#    #+#             */
/*   Updated: 2022/10/11 02:26:28 by elehtora         ###   ########.fr       */
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
const char	*set_flags(const char *init, t_fstring *fs)
{
	const size_t	n_flags = ft_strspn(init, FLAGS);
	const char		*flagset = ft_strgetset(init, FLAGS, "", n_flags);

	if (!flagset)
		return (init);
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
	return (init + n_flags);
}

/* Sets the maximum field width of a format string, limited by INT_MAX.
 * Field width never truncates a value.
 * Returns a pointer to the character after the last digit of the field width
 * string.
 */
const char	*set_field_width(const char *init, t_fstring *fs)
{
	const char	*iterator = ft_strpbrk(init, FWIDTH_DIGITS);
	char		buf[FWIDTH_MAXCHARS];
	int			i;

	if (!iterator || ft_strspn(init, FWIDTH_DIGITS) == 0)
		return ((char *)init);
	if (*iterator == '*')
	{
		i = va_arg(*fs->ap, int);
		if (i < 0)
			fs->format |= F_LEFT_ALIGN;
		fs->field_width = (int)ft_labs((long)i);
	}
	else
	{
		ft_bzero(&buf[0], FWIDTH_MAXCHARS);
		i = 0;
		while (ft_isdigit(*iterator))
			buf[i++] = *iterator++;
		if (buf[0] != 0)
			fs->field_width = ft_atoi(&buf[0]);
	}
	return ((char *)iterator);
}

/* Sets the precision for a format string.
 * Returns a pointer to the precision specifying dot before the first digit.
 */
const char	*set_precision(const char *init, t_fstring *fs)
{
	const char	*dot = ft_memchr(init, '.', fs->type - init);
	char		precision_str[PRECISION_BUF_SIZE];
	int			i;

	if (!dot || *(dot + 1) == '-')
		return ((char *)init);
	if (ft_memchr(dot, '*', fs->type - dot))
	{
		i = va_arg(*fs->ap, int);
		if (i < 0)
			return (dot);
		fs->precision = i;
		fs->format ^= EXPL_PRECISION;
		return (dot);
	}
	fs->format ^= EXPL_PRECISION;
	ft_bzero(&precision_str[0], PRECISION_BUF_SIZE);
	i = 0;
	while (ft_isdigit(dot[++i]) && i < PRECISION_BUF_SIZE)
		precision_str[i - 1] = dot[i];
	fs->precision = ft_atoi(&precision_str[0]);
	return (dot + i);
}

/* Seeks and sets the length modifiers hh, h, l, ll and L; char, short,
 * long, long long and long double, respectively, in a bit field.
 * Returns a pointer to the first modifier character, or NULL,
 * if no length modifer was found.
 */
void	set_length_modifier(const char *init, t_fstring *fs)
{
	const char	*mod = ft_strpbrk(init, LENMODS);

	if (!mod || !(mod + 1 == fs->type || mod + 2 == fs->type))
		return ;
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
}
