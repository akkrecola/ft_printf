/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:37:42 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/25 17:43:30 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Applies format string data to a string conversion 's', and saves a resulting
 * string to fs->string. (All result values end up in fs->string - naming is
 * coincidental).
 */
void	convert_string(t_fstring *fs, va_list *ap)
{
	const char	*arg = (const char *)va_arg(*ap, char *);

	if (arg == NULL)
	{
		if (fs->format & EXPL_PRECISION)
			fs->string = ft_strndup("(null)", fs->precision);
		else
			fs->string = ft_strdup("(null)");
	}
	else if (fs->format & EXPL_PRECISION)
		fs->string = ft_strndup(arg, fs->precision);
	else
		fs->string = ft_strdup(arg);
	if (!fs->string)
		error(fs);
	fs->len = ft_strlen(fs->string);
	if (fs->field_width > fs->len)
		expand_to_field_width(fs);
}

/* Applies format string data to a char 'c' conversion, saving the result.
 */
void	convert_char(t_fstring *fs, va_list *ap)
{
	const unsigned char	c = (const unsigned char)va_arg(*ap, int);

	fs->string = ft_strnew(1);
	if (!fs->string)
		error(fs);
	fs->string[0] = c;
	fs->len = 1;
	if (fs->field_width > fs->len)
		expand_to_field_width(fs);
}

/* Literal percent character '%', with formatting data applied is saved to
 * fs->string.
 */
void	give_percent(t_fstring *fs, va_list *ap)
{
	(void)ap;
	fs->string = ft_strdup("%");
	if (!fs->string)
		error(fs);
	fs->len = 1;
	if (fs->field_width > fs->len)
		expand_to_field_width(fs);
}
