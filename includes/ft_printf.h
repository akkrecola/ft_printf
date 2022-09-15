/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:00:21 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/15 18:00:07 by elehtora         ###   ########.fr       */
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
# define CMASK_CHAR 0x220
// padding until bit position 12
// Conversion (F)lags. Some of these are mutually exclusive.
// #0-(space)+' bit positions 12-16
# define F_ALT_FORM 0x1000
# define F_ZERO_PAD 0x2000
# define F_RIGHT_PAD 0x4000
# define F_SPACE_SIGN 0x8000
# define F_FORCE_SIGN 0x10000
// Padding until 20
// Length modifiers hh, h, l, ll. (20-23)
# define M_CHAR 0x1000000
# define M_SHORT 0x2000000
# define M_LONG 0x4000000
# define M_LONGLONG 0x8000000
// Padding until 28
# define IS_FIELD_WIDTH 0x10000000 //low prio
# define IS_PRECISION 0x20000000 //low prio
// Limits
# define MAX_FIELD_WIDTH 2147483646 // INT_MAX - 1
# define MAX_PRECISION 2147483646 //FLOAT IS THIS - 2? wut
//# define DEFAULT_FORMAT // precision is 6 by default


# define SPEC_TYPES "diouxXfcsp%"
# define FLAG_CHARS "#0- +"

// A conversion specification has format values at least at the bit area that
// is appointed to holding the (mandatory) conversion specifier.
typedef struct s_fstring
{
	uint32_t	format;
	uint32_t	field_width;
	uint32_t	precision;
	char		*type;
	char		*string;
}	t_fstring;

int	ft_printf(const char *format, ...) __attribute__ ((format (printf, 1, 2)));

// Conversion handlers
int	convert_signed_int(t_fstring *fstring, long arg);
int	convert_unsigned_int(t_fstring *fstring, unsigned long arg);
int	convert_string(t_fstring *fstring, const char *arg);
int	convert_char(t_fstring *fstring, unsigned char arg);
int	convert_double(t_fstring *fstring, double arg);
int	convert_void(t_fstring *fstring, void *arg);

char	*format_hex(unsigned long arg, t_fstring *fstring);

#endif
