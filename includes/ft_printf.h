/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:00:21 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/21 01:56:50 by elehtora         ###   ########.fr       */
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
// Following bit positions act as indices, so the range for uint64_t is 0-63.
// (C)onversion specifiers as bit flags. These are all mutually EXCLUSIVE.
// Since the conversion specification read stops when first specifier is found,
// there won't (shouldn't) ever be multiple specifiers set.
# define FORMAT_ERROR 0xFFFFFFFF
// [d|i]uoxX (bit positions 0-4)
# define C_SDEC 0x1
# define C_UDEC 0x2
# define C_UOCT 0x4
# define C_UHEX_LOW 0x8
# define C_UHEX_CAP 0x10
// Masks
# define CMASK_HEX 0x18
# define CMASK_UDEC 0x1F
// cspf, (bit positions 5-8)
# define C_CHAR 0x20
# define C_STRING 0x40
# define C_VOIDHEX 0x80
# define C_FLOAT 0x100
# define C_INIT 0x200
# define CMASK_ALL 0x3FF
// padding until bit position 12
// Conversion (F)lags. Some of these are mutually exclusive.
// #0-(space)+' bit positions 12-16
# define F_ALT_FORM 0x1000
# define F_ZERO_PAD 0x2000
# define F_LEFT_ALIGN 0x4000
# define F_SPACE_SIGN 0x8000
# define F_FORCE_SIGN 0x10000
# define MASK_FLAGS 0x1F000
# define MASK_HEX_PREFIX 0x1080
// Padding until 20
// Length modifiers hh, h, l, ll. (20-23)
# define M_CHAR 0x1000000
# define M_SHORT 0x2000000
# define M_LONG 0x4000000
# define M_LONGLONG 0x8000000
# define EXPL_FIELD_WIDTH 0x10000000 //low prio
# define EXPL_PRECISION 0x20000000
# define EXPL_FLAGS 0x40000000
# define EXPL_EXPAND_PRECISION 0x80000000
// Limits
# define MAX_FIELD_WIDTH 2147483647 // INT_MAX
# define MAX_PRECISION 2147483647 // INT_MAX
//# define DEFAULT_FORMAT // precision is 6 by default


# define SPEC_TYPES "diouxXfcsp%"
# define NOT_SPEC_TYPES "#0- + 123456789."
# define FLAGS "#0- +"
# define FWIDTH_DIGITS "123456789"
// Delimiting characters for each format parser function (set_*())
# define FLAG_DELIMS "123456789.lhLdiouxXfcsp%"
# define FWIDTH_DELIMS ".lhLdiouxXfcsp%" // Precision id + length mods
# define ALL_FCHARS "#0- + 123456789.lhLdiouxXfcsp%"

// Default values for format information
# define DEFAULT_PRECISION 0
# define DEFAULT_FLOAT_PRECISION 6
# define DEFAULT_FWIDTH 0

// A conversion specification has format values at least at the bit area that
// is appointed to holding the (mandatory) conversion specifier.
typedef struct s_fstring
{
	char		*type;
	char		*string;
	char		*sign; // Used to adjust field width
	uint32_t	format;
	uint32_t	field_width;
	uint32_t	precision;
}	t_fstring;

int	ft_printf(const char *format, ...) __attribute__ ((format (printf, 1, 2)));

// Format string parsers and data collectors
uint32_t	set_type(const char *type); // FIXME Unify with other setting functions
void		set_flags(const char *init, const char *delim, t_fstring *fs);
char		*set_field_width(const char *init, const char *delim, t_fstring *fs);
char		*set_precision(const char *init, const char *delim, t_fstring *fs);

// Conversion handlers
int	convert_signed_int(t_fstring *fs, long long int arg);
int	convert_unsigned_int(t_fstring *fs, unsigned long long int arg);
int	convert_string(t_fstring *fs, const char *arg);
int	convert_char(t_fstring *fs, unsigned char arg);
int	convert_double(t_fstring *fs, double arg);
int	convert_void(t_fstring *fs, void *arg);
int	give_percent(t_fstring *fs);

char	*format_hex(unsigned long long arg, t_fstring *fs);
char	*format_oct(unsigned long long arg, t_fstring *fs);

int		align_left(t_fstring *fs, char *left_adjusted_str);
int		expand_to_field_width(t_fstring *fs);
void	prepend_sign(t_fstring *fs);
void	add_hex_prefix(t_fstring *fs);
#endif
