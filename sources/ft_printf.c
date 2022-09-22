/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:10:19 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/23 02:32:52 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "dispatch.h"

static t_fstring	*init_fstring(void)
{
	t_fstring	*fs;

	fs = malloc(sizeof(t_fstring));
	if (!fs)
		return (NULL);
	fs->format = 0x0;
	fs->field_width = 0;
	fs->precision = 0;
	fs->string = NULL;
	fs->sign = NULL;
	fs->len = 0;
	return (fs);
}

// Frees all memory of fs. No return value since free() returns void.
static void	free_fstring(t_fstring *fs)
{
	if (fs)
	{
		if (fs->string)
			free(fs->string);
		free(fs);
	}
}

// Gets the formatting information for the next argument, read from the format
// string.
// Most of the format setting functions return a pointer to the format string
// position where that specific modification has been cleared.
static t_fstring	*get_next_format(const char *init)
{
	const char	*type = ft_strpbrk(init + 1, SPEC_TYPES);
	const char	*delimiter = init + ft_strspn(init, ALL_FCHARS);
	t_fstring	*fs;

	fs = init_fstring();
	if (!fs)
		return (NULL);
	if (!type || type > delimiter) //fallback;
	{
		fs->type = (char *)delimiter;
		return (fs);
	}
	fs->format |= set_type(type);
	fs->type = (char *)type;
	delimiter = set_precision(init, type, fs);
	delimiter = set_field_width(init, delimiter, fs);
	set_flags(init, delimiter, fs);
	return (fs);
}

// Applies the previously gathered format information to the parameter.
static int			convert_fstring(t_fstring *fs, va_list *ap)
{
	return (g_convert[(fs->format & CMASK_ALL) - 1](fs, ap)); // TODO requires header convspec formatting
}

int					ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*initializer;
	size_t		printed;
	t_fstring	*fs;

	va_start(ap, format);
	printed = 0;
	fs = NULL;
	while (1)
	{
		free_fstring(fs);
		initializer = ft_strchr(format, '%');
		if (!initializer)
		{
			printed += write(1, format, ft_strlen(format));
			break ;
		}
		printed += write(1, format, initializer - format);
		fs = get_next_format(initializer);
		if (!(fs->format & CMASK_ALL))
		{
			format = fs->type;
			if (!format) // fs allocation failed
				return (-1);
			continue ;
		}
		if (!fs || !convert_fstring(fs, &ap)) // TODO Collapse convert_fstring straight as convert[]()
			return (-1);
		printed += write(1, fs->string, fs->len);
		format = fs->type + 1;
		va_end(ap);
	}
	return ((int)printed);
}
