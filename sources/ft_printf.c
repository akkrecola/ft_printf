/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:10:19 by elehtora          #+#    #+#             */
/*   Updated: 2022/06/18 23:26:11 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

Appends an fstring list item to a list. If the list
static void	append_fstring(t_fstring *new, t_fstring **head)
{
	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		while ((*head)->next != NULL)
			head++;
		
	}
}

/*
 * Matches the conversion specifier character and returns it's corresponding
 * bit flag. The order is supposed to be optimised for the most common use:
 * fewer calls are made to octal 'o' than string 's', etc.
 *
 * Total of 10.
 */
static uint32_t	set_specifier(const char *delim)
{
	if (delim == 'd' || delim == 'i') // they're the same thing
		return (C_SDEC);
	else if (delim == 'u')
		return (C_UDEC);
	else if (delim == 's')
		return (C_STRING);
	else if (delim == 'c')
		return (C_CHAR);
	else if (delim == 'p')
		return (C_VOIDHEX);
	else if (delim == 'x')
		return (C_UHEX_LOW);
	else if (delim == 'X')
		return (C_UHEX_CAP);
	else if (delim == 'f')
		return (C_FLOAT);
	else if (delim == 'o')
		return (C_UOCT);
	return (error(INVALID_DELIM));
}

static void 

/*
 * TODO This can't happen straight away, since we don't know the string size
 * before expanding the specifications.
 *
 * TODO OR can we? Struct is just storing a pointer to char, not the actual string.
 */
static t_fstring	*init_fstring(const char *spec, const char *delim)
{
	t_fstring	fstring;

	fstring.format = 0;
	fstring.format |= set_specifier(*delim);
	if (!fstring.format)
		return (NULL);
	fstring.format |= set_flags();
	/*TODO Check for overlapping flags with bitmasking*/
	fstring.next = NULL;
}

/*
 * Identifying the (1) literal strings and (2) conversion specifications and
 * iterating a constructor for fstring structs.
 */
static char	*parse_fstrings(const char *format, t_fstring **p_fstring)
{
	const char	*specifier = ft_strpbrk(format, "%\0");
	const char	*delim = ft_strpbrk(specifier + 1, conv_specs);
	const char	*conv_specs = "diouxXfFcsp%";

	if (specifier == NULL) // this happens only when 'format' is not null terminated.
		return (NULL);
	if (*specifier == '%')
	{
		
		if (append_fstring(init_fstring(specifier, delim)))
			return (NULL);
		return (specifier);
	}
	else if (*specifier == '\0') // 'unnecessary' check but brings clarity
		return (specifier); // check in caller if we reached the end of format
}

/*
 * Reading could be delimited by newlines instead of buffering the entire format
 * for one-time reading. For a (stupidly) big format string with multiple
 * newlines this should prove to be more efficient than just powering through
 */
int	ft_printf(const char *format, ...) // see if 'restrict'
{
	va_list ap;
	t_fstring	*fstrings; // HEAD

	fstrings = NULL;
	while (parse_fstrings(format, &fstrings));	// parse format string before variadic stuff
	va_start(ap, format);
	va_end(ap);
}
