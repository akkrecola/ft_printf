/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:10:19 by elehtora          #+#    #+#             */
/*   Updated: 2022/06/19 21:30:25 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
 * Appends an fstring list item to a list. If the list is empty, 'new'
 * is made the head of the list. Otherwise, 'new' is appended as the tail of
 * the list.
 */
static void	append_fstring(t_fstring *new, t_fstring **head)
{
	if (*head == NULL)
		*head = new;
	else
	{
		while ((*head)->next != NULL)
			head++;
		(*head)->next = new;
	}
}

/*
 * Matches the conversion specifier character and returns it's corresponding
 * bit flag. The order is supposed to be optimised for the most common use:
 * fewer calls are made to octal 'o' than string 's', etc.
 *
 * Total of 10.
 */
static void	set_specifier(const char delim)
{
	if (delim == 'd' || delim == 'i') // they're the same thing
		*format |= C_SDEC;
	else if (delim == 'u')
		*format |= C_UDEC;
	else if (delim == 's')
		*format |= C_STRING;
	else if (delim == 'c')
		*format |= C_CHAR;
	else if (delim == 'p')
		*format |= C_VOIDHEX;
	else if (delim == 'x')
		*format |= C_UHEX_LOW;
	else if (delim == 'X')
		*format |= C_UHEX_CAP;
	else if (delim == 'f')
		*format |= C_FLOAT;
	else if (delim == 'o')
		*format |= C_UOCT;
}

static void	set_flags(uint32_t *format, const char *specifier, const char *delim)
{

}

/*
 * TODO This can't happen straight away, since we don't know the string size
 * before expanding the specifications.
 *
 * TODO OR can we? Struct is just storing a pointer to char, not the actual string.
 */
static t_fstring	*init_fstring(const char *specifier, const char *delim)
{
	t_fstring	fstring;

	fstring.format = 0;
	fstring.next = NULL;
	if (*specifier != '%')										// (1) literal string
		fstring.string = ft_strddup(specifier, *delim);
	else														// (2) conversion
	{
		if (*delim == '%')
			fstring.format |= set_specifier(*delim);
		if (!fstring.format)
			return (NULL);
		set_flags(&fstring.format, spec, *delim);
		/*TODO Check for overlapping flags with bitmasking*/
	}
}

/*
 * Identifying the (1) literal strings and (2) conversion specifications and
 * iterating a constructor for fstring structs.
 */
/*
 * TODO Split this into a driver function and a parser per fstring. Clearer in
 * terms of the division into literal strings and conversion specs.
 */
static char	*parse_fstrings(const char *format, t_fstring **p_fstring)
{
	const char	*conv_specs = "diouxXfFcsp%";
	char		current;
	char		*specifier;
	char		*delim;
	uint32_t	i;

	i = 0;
	while (format[i] != '\0')
	{
		specifier = ft_strpbrk(format, "%\0");
		if (specifier == NULL) // this happens only when 'format' is not null terminated.
			return (NULL);
		if (*specifier == '%')
		{
			delim = ft_strpbrk(specifier + 1, conv_specs);
			if (&format[i] != specifier)
				append_fstring(init_fstring(&format[i], specifier));	//literal string
			append_fstring(init_fstring(specifier, delim);
					return (specifier);
					}
					else if (*specifier == '\0') // 'unnecessary' check but brings clarity
					return (specifier); // check in caller if we reached the end of format
					i += ft_strdlen(&format[i], delim); //Index to the character after delimiter (can be null, checked by parent while)
					}
					}

					/*
					 * Reading could be delimited by newlines instead of buffering the entire format
					 * for one-time reading. For a (stupidly) big format string with multiple
					 * newlines this should prove to be more efficient than just powering through
					 */
					int	ft_printf(const char *format, ...) // see if 'restrict'
					{
					va_list		ap;
					t_fstring	*fstrings; // HEAD
					size_t		ret;

					fstrings = NULL;
					parse_fstrings(format, &fstrings);	// parse format string before variadic stuff
					va_start(ap, format);
					va_end(ap);
					}
