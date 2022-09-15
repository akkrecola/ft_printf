/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:10:19 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/15 06:36:28 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uint32_t		set_type(const char *type)
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

static t_fstring	*init_fstring(void)
{
	t_fstring	*fstring;
	fstring = malloc(sizeof(t_fstring));
	if (!fstring)
		return (NULL);
	fstring->format = 0x0;
	fstring->field_width = 0;
	fstring->precision = 0;
	fstring->string = NULL;

	return (fstring);
}

// Gets the formatting information for the next argument, read from the format
// string.
static t_fstring	*get_next_format(const char *initializer)
{
	const char	*type = ft_strpbrk(initializer + 1, SPEC_TYPES);
	t_fstring	*fstring;

	fstring = init_fstring();
	if (!fstring || !type)
		return (NULL);
	fstring->format |= set_type(type);
	fstring->type = (char *)type;

	return (fstring);
}

// Applies the previously gathered format information to the parameter.
static int			convert_fstring(t_fstring *fstring, va_list *ap)
{
	// On error: status == 0
	int	status;

	status = 0;
	// Dispatch formatting based on type
	if (fstring->format & C_SDEC)
		status = convert_signed_int(fstring, va_arg(*ap, int));
	else if (fstring->format & CMASK_UDEC)
		status = convert_unsigned_int(fstring, va_arg(*ap, unsigned int));
	else if (fstring->format & C_FLOAT)
		status = convert_double(fstring, va_arg(*ap, double));
	else if (fstring->format & CMASK_CHAR)
		status = convert_char(fstring, (unsigned char) va_arg(*ap, int));
	else if (fstring->format & C_STRING)
		status = convert_string(fstring, va_arg(*ap, const char *));
	else if (fstring->format & C_VOIDHEX)
		status = convert_void(fstring, va_arg(*ap, void *));
	return (status);
}

// Frees all memory of fstring. No return value since free() returns void.
static void	free_fstring(t_fstring *fstring)
{
	if (fstring)
	{
		if (fstring->string)
			free(fstring->string);
		free(fstring);
	}
}

int					ft_printf(const char *format, ...)
{
	va_list		ap; // Variable arguments list (see: man stdarg)
	char		*initializer; // Pointer to % character that inits conversion
	size_t		printed; // Bytes printed
	t_fstring	*fstring;

	// Start the variable argument list
	va_start(ap, format);
	initializer = NULL;
	printed = 0;
	fstring = NULL;

	// Print/format through the format string until we hit null byte
	while (1)
	{
		free_fstring(fstring); // Need a breakdown function for fstring->string alloc
		// Look for a format initializer
		initializer = ft_strchr(format, '%');
		// Print until initializer or null byte
		if (initializer != NULL)
		{
			// Write until format initializer
			printed += write(1, format, initializer - format);
			fstring = get_next_format(initializer);
			if (!fstring || !convert_fstring(fstring, &ap))
				return (-1);
			write(1, fstring->string, ft_strlen(fstring->string)); //output formatted
			format = fstring->type + 1;
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
