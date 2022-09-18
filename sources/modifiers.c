/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 01:18:59 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/19 05:16:36 by elehtora         ###   ########.fr       */
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

void	set_flags(const char *init, const char *delim, t_fstring *fs)
{
	const char	*flagset = ft_strgetset(init, FLAGS, "", delim - init);

	if (!flagset) // strgetset returns with malloc
		return ;
#ifdef DEBUG
	ft_putstr(flagset);
#endif
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
	if (fs->format & MASK_FLAGS)
		fs->format ^= EXPL_FLAGS;
#ifdef DEBUG
	if (fs->format & MASK_FLAGS) // FIXME Debug
		ft_putstr("Flags set.\n");
	if (fs->format & F_ALT_FORM)
		ft_putstr("ALT FORM FLAG set.\n");
	if (fs->format & F_LEFT_ALIGN)
		ft_putstr("LEFT ALIGN FLAG set.\n");
	if (fs->format & F_ZERO_PAD)
		ft_putstr("ZERO PAD FLAG set.\n");
	if (fs->format & F_FORCE_SIGN)
		ft_putstr("FORCE SIGN FLAG set.\n");
	if (fs->format & F_SPACE_SIGN)
		ft_putstr("SPACE SIGN FLAG set.\n");
#endif
	free((char *)flagset);
}

// TODO
#define FWIDTH_MAXCHARS 10
char	*set_field_width(const char *init, const char *delim, t_fstring *fs)
{
	const char	*iterator = ft_strpbrk(init, FWIDTH_DIGITS); // Find a starting digit (nonzero)
	char		buf[FWIDTH_MAXCHARS]; // INT_MAX is 10 in length
	uint8_t		i;

	if (!iterator)
		return ((char *)delim); // No field width
	ft_bzero(&buf[0], FWIDTH_MAXCHARS);
	i = 0;
	while (ft_isdigit(*iterator) && iterator != delim)
		buf[i++] = *iterator++;
	if (buf[0] != 0) // fwidth catched
	{
		fs->field_width = ft_atoi(&buf[0]);
		fs->format ^= EXPL_FIELD_WIDTH;
#ifdef DEBUG
	ft_putstr("Field width:\t");
	ft_putnbr(fs->field_width);
	ft_putchar('\n');
	if (fs->format & EXPL_FIELD_WIDTH)
		ft_putstr("Explicit field width SET\n");
#endif
	}
#ifdef DEBUG
	ft_putstr("Set_field_width returns: ");
	ft_putstr((char *)iterator - i);
	ft_putchar('\n');
#endif
	return ((char *)iterator - i); // first digit
}

#define PRECISION_BUF_SIZE 10 // TODO Check if this can be overflown
// Sets the precision for a format string.
// Returns a pointer to character after the last digit.
char	*set_precision(const char *init, const char *delim, t_fstring *fs)
{
	char		*dot;
	char		precision_str[PRECISION_BUF_SIZE];
	uint32_t	precision_val;
	uint32_t	i;

	dot = ft_memchr(init, '.', delim - init);
	if (!dot || *(dot + 1) == '-') // No dot or negative input == omit
		return ((char *)delim); // fs->type
	fs->format ^= EXPL_PRECISION;
#ifdef DEBUG
	if (fs->format & EXPL_PRECISION)
		ft_putstr("EXPL_PRECISION SET\n");
#endif
	ft_bzero(&precision_str[0], PRECISION_BUF_SIZE);
	i = 1; // Skip dot
	while (ft_isdigit(dot[i]) && i < PRECISION_BUF_SIZE)
	{
		precision_str[i - 1] = dot[i];
		i++;
	}
	precision_val = (uint64_t)ft_atoi(&precision_str[0]); // FIXME atol()
	if (precision_val < MAX_PRECISION)
		fs->precision = precision_val;
	return (dot); // Dot
}
