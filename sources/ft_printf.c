/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:10:19 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/21 02:57:19 by elehtora         ###   ########.fr       */
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
	fs->precision = 0;
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
		/*if (*delimiter == '\0')*/
			/*ft_putstr("Is null\n");*/
		/*ft_putstr(delimiter);*/
		/*ft_putnbr(ft_strspn(init, ALL_FCHARS));*/
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
	int	status;

	status = 0;
	if (fs->format & C_SDEC)
		status = convert_signed_int(fs, va_arg(*ap, long long int));
	else if (fs->format & CMASK_UDEC)
		status = convert_unsigned_int(fs, va_arg(*ap, unsigned long long int));
	else if (fs->format & C_FLOAT)
		status = convert_double(fs, va_arg(*ap, double));
	else if (fs->format & C_CHAR)
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
#define DEBUG
#ifdef DEBUG
		/*if (*format == '\0')*/
			/*ft_putstr("format is null\n");*/
		/*ft_putstr("Initializer: ");*/
		/*ft_putstr(initializer);*/
		/*ft_putstr("\n");*/
#endif
		if (!initializer)
		{
			/*printed += write(1, format, 0);*/
			printed += write(1, format, ft_strlen(format));
			break;
		}
#ifdef DEBUG
		/*ft_putstr("Format: ");*/
		/*ft_putstr(format);*/
		/*ft_putstr("\n");*/
#endif
		printed += write(1, format, initializer - format);
		fs = get_next_format(initializer);
		if (!(fs->format & CMASK_ALL))
		{
			/*ft_putstr("Yeehaw!\n");*/
			format = fs->type;
			if (!format) // fs allocation failed
				return (-1);
			/*ft_putstr(format);*/
			continue ;
		}
		if (!fs || !convert_fstring(fs, &ap))
			return (-1);
		printed += write(1, fs->string, ft_strlen(fs->string));
		format = fs->type + 1;
		va_end(ap);
	}
	return ((int)printed);
}
