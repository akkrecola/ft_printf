/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:00:21 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/24 15:42:40 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
// # define DEBUG

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
// [d|i]uoxX (bits 0-4 enumerated)
# define C_SDEC 0x1
# define C_UOCT 0x2
# define C_UDEC 0x3
# define C_UHEX_LOW 0x4
# define C_UHEX_CAP 0x5
// cspf, (bit indices )
# define C_CHAR 0x6
# define C_STRING 0x7
# define C_VOIDHEX 0x8
# define C_FLOAT 0x9
# define C_INIT 0xA
// Masks
# define CMASK 0xF
# define HEX_MASK 0x4
//# define CMASK_HEX 0x18
//# define CMASK_UDEC 0x1F
// padding until bit index 4
// Conversion (F)lags. Some of these are mutually exclusive.
// (F)lags '#0- +' bit positions 12-16
# define FLAGS "#0- +"
# define F_ALT_FORM 0x10
# define F_ZERO_PAD 0x20
# define F_LEFT_ALIGN 0x40
# define F_SPACE_SIGN 0x80
# define F_FORCE_SIGN 0x100
# define MASK_FLAGS 0x1F0
# define MASK_HEX_PREFIX 0x18
// Padding until 20
// Length modifiers hh, h, l, ll. (20-23)
# define LENMODS "hl"
# define M_CHAR 0x200
# define M_SHRT 0x400
# define M_LONG 0x800
# define M_LLONG 0x1000
// Explicitly set flags for modifiers
# define EXPL_PRECISION 0x2000
# define EXPL_LENGTH_MOD 0x4000 // TODO Check if needed
// Limits TODO needed?
# define MAX_FIELD_WIDTH 2147483647 // INT_MAX
# define MAX_PRECISION 2147483647 // INT_MAX

// Delimiter string constants for parsing the format string
//# define NOT_SPEC_TYPES "#0- + 123456789."
# define FWIDTH_DIGITS "123456789"
// Delimiting characters for each format parser function (set_*())
//# define FLAG_DELIMS "123456789.lhLdiouxXfcsp%"
//# define FWIDTH_DELIMS ".lhLdiouxXfcsp%" // Precision id + length mods
# define ALL_FCHARS "#0- + 123456789.lhLdiouxXfcsp%"

// Default values for format information
// # define DEFAULT_PRECISION 0
# define DEFAULT_FLOAT_PRECISION 6
// # define DEFAULT_FWIDTH 0

// A conversion specification has format values at least at the bit area that
// is appointed to holding the (mandatory) conversion specifier.
typedef struct s_fstring
{
	char		*type;
	char		*string;
	char		*sign;
	uint16_t	format; // TODO Check if 16 bits is OK
	uint32_t	field_width;
	uint32_t	precision;
	uint32_t	len;
}	t_fstring;

int	ft_printf(const char *format, ...) __attribute__ ((format (printf, 1, 2)));

// Format string parsers and data collectors
uint16_t	set_type(const char *type); // FIXME Unify with other setting functions
void		set_flags(const char *init, const char *delim, t_fstring *fs);
const char	*set_field_width(const char *init, const char *delim, t_fstring *fs);
const char	*set_precision(const char *init, const char *delim, t_fstring *fs);
const char	*set_length_modifier(const char *init, const char *delim, t_fstring *fs);

// Conversion handlers
int	convert_signed_int(t_fstring *fs, va_list *ap);
int	convert_unsigned_int(t_fstring *fs, va_list *ap);
int	convert_string(t_fstring *fs, va_list *ap);
int	convert_char(t_fstring *fs, va_list *ap);
int	convert_double(t_fstring *fs, va_list *ap);
int	convert_void(t_fstring *fs, va_list *ap);
int	give_percent(t_fstring *fs, va_list *ap);

int		format_hex(unsigned long long arg, t_fstring *fs);
int		format_oct(unsigned long long arg, t_fstring *fs);

int		align_left(t_fstring *fs, char *left_adjusted_str);
int		expand_to_field_width(t_fstring *fs);
void	prepend_sign(t_fstring *fs);
int		add_hex_prefix(t_fstring *fs);
void	set_explicit_zero(t_fstring *fs);
int		pad_integer_precision(t_fstring *fs);

#endif
