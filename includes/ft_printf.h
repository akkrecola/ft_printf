/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:00:21 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/25 04:44:56 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "libft.h"

# define FORMAT_ERROR 0xFFFF
// Following bits act as indices for the conversion dispatch table.
// (C)onversion specifiers as bit enumeration. These are all mutually EXCLUSIVE.
// NOTE: 0x0 is reserved for empty format string (default).
# define SPEC_TYPES "diouxXfcsp%"
# define NUM_TYPES "diouxX"
// [d|i]uoxX (bits 0-4 enumerated) (numerics)
# define C_SDEC 0x1
# define C_UOCT 0x2
# define C_UDEC 0x3
# define C_UHEX_LOW 0x4
# define C_UHEX_CAP 0x5
// cspf
# define C_CHAR 0x6
# define C_STRING 0x7
# define C_VOIDHEX 0x8
# define C_FLOAT 0x9
# define C_INIT 0xA
// Bitmasks for comparisons
# define CMASK 0xF
# define HEX_MASK 0x4

// Conversion (F)lags. Some of these are mutually exclusive.
# define FLAGS "#0- +"
# define F_ALT_FORM 0x10
# define F_ZERO_PAD 0x20
# define F_LEFT_ALIGN 0x40
# define F_SPACE_SIGN 0x80
# define F_FORCE_SIGN 0x100
# define MASK_FLAGS 0x1F0
# define MASK_HEX_PREFIX 0x18

// Length modifiers hh, h, l, ll. (20-23)
# define LENMODS "hlL"
# define M_CHAR 0x200
# define M_SHRT 0x400
# define M_LONG 0x800
# define M_LLONG 0x1000
# define M_DLONG 0x2000

// Toggle explicitly set precision flag
# define EXPL_PRECISION 0x4000

// Limits
# define MAX_PRECISION 2147483647 // INT_MAX

// Delimiter string constants for parsing the format string
# define FWIDTH_DIGITS "123456789"
# define ALL_FCHARS "#0- + 123456789.lhLdiouxXfcsp%"

// A conversion specification has format values at least at the bit area that
// is appointed to holding the (mandatory) conversion specifier.
typedef struct s_fstring
{
	char		*type;
	char		*string;
	char		*sign;
	uint16_t	format;
	uint32_t	field_width;
	uint32_t	precision;
	uint32_t	len;
}	t_fstring;

// Function entry
int			ft_printf(const char *format, ...) \
				__attribute__ ((format (printf, 1, 2)));

// Format string parsers and data collectors
uint16_t	set_type(const char *type);
void		set_flags(const char *init, const char *delim, t_fstring *fs);
const char	*set_field_width(const char *init, \
		const char *delim, t_fstring *fs);
const char	*set_precision(const char *init, const char *delim, t_fstring *fs);
const char	*set_length_modifier(const char *init, \
		const char *delim, t_fstring *fs);

// Conversion handlers
int			convert_signed_int(t_fstring *fs, va_list *ap);
int			convert_unsigned_int(t_fstring *fs, va_list *ap);
int			convert_string(t_fstring *fs, va_list *ap);
int			convert_char(t_fstring *fs, va_list *ap);
int			convert_double(t_fstring *fs, va_list *ap);
int			convert_void(t_fstring *fs, va_list *ap);
int			give_percent(t_fstring *fs, va_list *ap);

// Formatters
int			format_hex(unsigned long long arg, t_fstring *fs);
int			format_oct(unsigned long long arg, t_fstring *fs);

// Conversion string manipulation
int			align_left(t_fstring *fs, char *left_adjusted_str);
int			expand_to_field_width(t_fstring *fs);
int			add_hex_prefix(t_fstring *fs);
int			pad_integer_precision(t_fstring *fs);
void		prepend_sign(t_fstring *fs);
void		set_explicit_zero(t_fstring *fs);

// Deallocation at program termination.
//void		teardown(t_fstring *fs);

#endif
