/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:10:19 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/14 19:04:36 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Gets the formatting information for the next argument, read from the format
// string.
static t_fstring	*get_next_format(const char *initializer)
{
	const char		*type = ft_strpbrk(initializer + 1, SPEC_TYPES);
	t_fstring		*fstring;

	fstring = malloc(sizeof(t_fstring));
	if (!fstring || !type)
		return (NULL);
	fstring->type = type;

	return (fstring);
}

static int			convert_fstring(t_fstring *fstring)
{
	fstring = fstring;
	return (1);
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
		// Look for a format initializer
		initializer = ft_strchr(format, '%');
		// Print until initializer or null byte
		if (initializer != NULL)
		{
			// Write until format initializer
			printed += write(1, format, initializer - format);
			// Free and save formatting information to a struct
			free(fstring);
			fstring = get_next_format(initializer);
			if (!fstring || !convert_fstring(fstring))
				return (-1);
			format = fstring->type + 1;
		}
		else
		{
			// If no format initializer, print the rest of the string, then break.
			printed += write(1, format, ft_strlen(format));
			free(fstring);
			break;
		}
		// Get the formatting information by filtering through format string
	}
	// Return number of characters printed
	return (printed);
}
