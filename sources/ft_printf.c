/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:10:19 by elehtora          #+#    #+#             */
/*   Updated: 2022/10/11 00:46:26 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "dispatch.h"

/* Initializes default/falseish values for the struct
 */
static void	init_fstring(t_fstring *fs, va_list *ap)
{
	fs->format = 0x0;
	fs->field_width = 0;
	fs->precision = 0;
	fs->string = NULL;
	fs->sign = NULL;
	fs->len = 0;
	fs->ap = ap;
}

/* Extracts formatting information for the next argument, read from the format
 * string 'format', saving everything to the format string struct type
 * t_fstring.
 *
 * Most of the format setting functions (set_*) return a pointer to the
 * format string position where that specific modification has been cleared.
 */
static const char	*get_next_format(t_fstring *fs, const char *init)
{
	const char	*type = ft_strpbrk(init + 1, SPEC_TYPES);
	const char	*confirm = init + ft_strspn(init, ALL_FCHARS);

	if (!type || type > confirm)
	{
		fs->format = FORMAT_ERROR;
		if (*confirm == '\0')
			return (confirm);
		else
			return (confirm + 1);
	}
	fs->format |= set_type(type);
	fs->type = (char *)type;
	init = set_flags(init + 1, fs);
	init = set_field_width(init, fs);
	init = set_precision(init, fs);
	set_length_modifier(init, fs);
	return (type + 1);
}

/* Deconstructs allocated structures and the variable argument list.
 */
void	teardown(t_fstring *fs)
{
	if (fs->string)
		ft_strdel(&fs->string);
	va_end(*fs->ap);
}

/* Entry function.
 *
 * Iterates through the format string by seeking a format
 * string initializing character '%', writing literal string
 * before and after the conversion takes place. Format
 * string is 'walked' by pointer returns from get_next_format().
 *
 * g_convert[]() is a function dispatcher, that centralizes
 * the variable argument type distribution to respective handlers
 * (prefixes 'convert*').
 *
 * Returns the total amount of bytes written to stdout, negative
 * (-1) on error.
 */
int	ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*initializer;
	size_t		printed;
	t_fstring	fs;

	va_start(ap, format);
	printed = 0;
	while (1)
	{
		init_fstring(&fs, &ap);
		initializer = ft_strchr(format, '%');
		if (!initializer)
			break ;
		printed += write(1, format, initializer - format);
		format = get_next_format(&fs, initializer);
		if (fs.format == FORMAT_ERROR)
			continue ;
		g_convert[(fs.format & CMASK) - 1](&fs, &ap);
		printed += write(1, fs.string, fs.len);
		ft_strdel(&fs.string);
	}
	printed += write(1, format, ft_strlen(format));
	teardown(&fs);
	return ((int)printed);
}
