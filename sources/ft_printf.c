/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:10:19 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/25 08:22:20 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "dispatch.h"

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

// Gets the formatting information for the next argument, read from the format
// string.
// Most of the format setting functions return a pointer to the format string
// position where that specific modification has been cleared.
static const char	*get_next_format(t_fstring *fs, const char *init)
{
	const char	*type = ft_strpbrk(init + 1, SPEC_TYPES);
	const char	*delimiter = init + ft_strspn(init, ALL_FCHARS);

	if (!type || type > delimiter)
	{
		fs->format = FORMAT_ERROR;
		if (*delimiter == '\0')
			return (delimiter);
		else
			return (delimiter + 1);
	}
	fs->format |= set_type(type);
	fs->type = (char *)type;
	delimiter = set_length_modifier(init, type, fs);
	delimiter = set_precision(init, delimiter, fs);
	delimiter = set_field_width(init, delimiter, fs);
	set_flags(init, delimiter, fs);
	return (type + 1);
}

void	teardown(t_fstring *fs)
{
	if (fs->string)
		ft_strdel(&fs->string);
	va_end(*fs->ap);
}

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
		if (!g_convert[(fs.format & CMASK) - 1](&fs, &ap))
			return (error(&fs));
		printed += write(1, fs.string, fs.len);
		ft_strdel(&fs.string);
	}
	printed += write(1, format, ft_strlen(format));
	teardown(&fs);
	return ((int)printed);
}
