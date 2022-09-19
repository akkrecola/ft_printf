/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:10:19 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/19 07:21:03 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_fstring	*init_fstring(void)
{
	t_fstring	*fs;

	fs = malloc(sizeof(t_fstring));
	if (!fs)
		return (NULL);
	fs->format = 0x0;
	fs->field_width = 0;
	fs->precision = DEFAULT_PRECISION;
	fs->string = NULL;
	fs->sign = NULL;

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
// TODO Literal %
static t_fstring	*get_next_format(const char *initializer)
{
	const char	*type = ft_strpbrk(initializer + 1, SPEC_TYPES);
	const char	*delimiter;
	t_fstring	*fs;

	fs = init_fstring();
	if (!fs || !type)
		return (NULL);
	fs->format |= set_type(type); // TODO add error check (if format == FORMAT_ERROR)
	fs->type = (char *)type;
	delimiter = set_precision(initializer, type, fs);
	delimiter = set_field_width(initializer, delimiter, fs); // FIXME hex segfault
	set_flags(initializer, delimiter, fs);
	return (fs);
}

// Applies the previously gathered format information to the parameter.
static int			convert_fstring(t_fstring *fs, va_list *ap)
{
	// On error: status == 0
	int	status;

	status = 0;
	// Dispatch formatting based on type
	if (fs->format & C_SDEC)
		status = convert_signed_int(fs, va_arg(*ap, long long int));
	else if (fs->format & CMASK_UDEC)
		status = convert_unsigned_int(fs, va_arg(*ap, unsigned long long int));
	else if (fs->format & C_FLOAT)
		status = convert_double(fs, va_arg(*ap, long double));
	else if (fs->format & CMASK_CHAR)
		status = convert_char(fs, (unsigned char) va_arg(*ap, int));
	else if (fs->format & C_STRING)
		status = convert_string(fs, va_arg(*ap, const char *));
	else if (fs->format & C_VOIDHEX)
		status = convert_void(fs, va_arg(*ap, void *));
	else if (fs->format & C_INIT)
		status = give_percent(fs); // TODO function just to set fs->string to '%'
	return (status);
}

int					ft_printf(const char *format, ...)
{
	va_list		ap; // Variable arguments list (see: man stdarg)
	char		*initializer; // Pointer to % character that inits conversion
	size_t		printed; // Bytes printed
	t_fstring	*fs;

	// Start the variable argument list
	va_start(ap, format);
	initializer = NULL;
	printed = 0;
	fs = NULL;
	// Print/format through the format string until we hit null byte
	while (1)
	{
		free_fstring(fs); // Need a breakdown function for fs->string alloc
		// Look for a format initializer
		initializer = ft_strchr(format, '%');
		// Print until initializer or null byte
		if (initializer != NULL)
		{
			// Write until format initializer
			printed += write(1, format, initializer - format);
			fs = get_next_format(initializer);
			if (!fs || !convert_fstring(fs, &ap))
				return (-1);
			write(1, fs->string, ft_strlen(fs->string)); //output formatted
			format = fs->type + 1;
		}
		else
		{
			// If no format initializer, print the rest of the string, then break.
			printed += write(1, format, ft_strlen(format));
			break;
		}
		va_end(ap);
	}
	// Return number of characters printed
	return (printed);
}
