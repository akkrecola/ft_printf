/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unittest.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:31:30 by elehtora          #+#    #+#             */
/*   Updated: 2022/07/01 21:30:10 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Header for ft_printf unit testing

#ifndef UNITTEST_PRINTF_H
# define UNITTEST_PRINTF_H

# define TEST_COUNT 1

// No conversion
int	noconv_helloworld(void);
int	noconv_emptystring(void);
int	noconv_newline(void);
int	noconv_helloworld_newline(void);

//Basic conversions
int	plain_literal_percent(void);
int	plain_signed_decimal(void);
int	plain_unsigned_decimal(void);
int	plain_octal(void);
int	plain_unsigned_hex_lowercase(void);
int	plain_unsigned_hex_uppercase(void);
int	plain_float(void);
int	plain_char(void);
int	plain_string(void);
int	plain_voidhex(void);

#endif
