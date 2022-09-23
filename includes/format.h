/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 03:25:01 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/23 03:25:44 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H

# define FORMAT_ERROR 0xFFFFFFFF
// Following bits act as indices for the conversion dispatch table.
// (C)onversion specifiers as bit enumeration. These are all mutually EXCLUSIVE.
// NOTE: 0x0 is reserved for empty format string (default).
# define SPEC_TYPES "diouxXfcsp%"
// [d|i]uoxX (bits 0-4 enumerated)
# define C_SDEC 0x1
# define C_UDEC 0x2
# define C_UOCT 0x3
# define C_UHEX_LOW 0x4
# define C_UHEX_CAP 0x5
// cspf, (bit indices )
# define C_CHAR 0x6
# define C_STRING 0x7
# define C_VOIDHEX 0x8 // This is lucky; no other bit is SET if VOIDHEX is the convspec => mask below SHOULD work(0b1000) (TODO check)
# define C_FLOAT 0x9
# define C_INIT 0xA
// Masks
# define CMASK_ALL 0xF // TODO reformat to CMASK
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
# define M_CHAR 0x200
# define M_SHORT 0x400
# define M_LONG 0x800
# define M_LONGLONG 0x1000
// Explicitly set flags for modifiers
# define EXPL_PRECISION 0x2000
# define EXPL_LENGTH_MOD 0x4000 // TODO Check if needed

#endif
