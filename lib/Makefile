# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 15:27:40 by elehtora          #+#    #+#              #
#    Updated: 2022/09/19 03:38:58 by elehtora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
# This makefile compiles the objects used in libft for use in the new library
# libftprintf.a. It is called recursively from the root Makefile, and is not
# intended to be used separately.
#
# This makefile hence does not need to adhere to the requirements of a
# regular building makefile, that is meant in the 42 Norm.
#

SRCS	=	ft_atoi.c			\
			ft_abs.c			\
			ft_bzero.c			\
			ft_del.c			\
			ft_count_digs.c		\
			ft_isalnum.c		\
			ft_isalpha.c		\
			ft_isascii.c		\
			ft_isdigit.c		\
			ft_islower.c		\
			ft_isprint.c		\
			ft_isupper.c		\
			ft_iswhite.c		\
			ft_arechars.c		\
			ft_itoa.c			\
			ft_ltoa.c			\
			ft_lstadd.c			\
			ft_lstcpyone.c		\
			ft_lstdel.c			\
			ft_lstdelone.c		\
			ft_lstiter.c		\
			ft_lstmap.c			\
			ft_lstnew.c			\
			ft_memalloc.c		\
			ft_memccpy.c		\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_memcpy.c			\
			ft_memdel.c			\
			ft_memmove.c		\
			ft_memrchr.c		\
			ft_memset.c			\
			ft_putchar.c		\
			ft_putchar_fd.c		\
			ft_putendl.c		\
			ft_putendl_fd.c		\
			ft_putmem.c			\
			ft_putnbr.c			\
			ft_putnbr_fd.c		\
			ft_putstr.c			\
			ft_putstr_fd.c		\
			ft_putbits.c		\
			ft_pow.c			\
			ft_charappend.c		\
			ft_strarrlen.c		\
			ft_strcat.c			\
			ft_strchr.c			\
			ft_strclr.c			\
			ft_strrclr.c		\
			ft_strcmp.c			\
			ft_strcpy.c			\
			ft_strdcpy.c		\
			ft_strdel.c			\
			ft_strdup.c			\
			ft_strndup.c		\
			ft_strddup.c		\
			ft_strequ.c			\
			ft_strgetset.c		\
			ft_striter.c		\
			ft_striteri.c		\
			ft_strjoin.c		\
			ft_strdjoin.c		\
			ft_strlen.c			\
			ft_strdlen.c		\
			ft_strmap.c			\
			ft_strmapi.c		\
			ft_strncat.c		\
			ft_strncmp.c		\
			ft_strncpy.c		\
			ft_strlcat.c		\
			ft_strlcpy.c		\
			ft_strnequ.c		\
			ft_strnew.c			\
			ft_strnlen.c		\
			ft_strnstr.c		\
			ft_strpbrk.c		\
			ft_strrchr.c		\
			ft_strrev.c			\
			ft_strsep.c			\
			ft_strsplit.c		\
			ft_strstr.c			\
			ft_strsub.c			\
			ft_strtrim.c		\
			ft_nat_sqrt.c		\
			ft_tolower.c		\
			ft_toupper.c

# 'objects' directory is created in project root
OBJDIR	:= ../objects
OBJS	:= $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
RM		:= /bin/rm -rf

# RULES
.PHONY: all clean re

all : $(OBJS)

$(OBJDIR)/%.o : %.c
	@echo "Creating object file:\t\033[1;32m$(<:.c=.o)\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@echo "\033[1;32mCleaning libft object files.\033[0m"
	@$(RM) $(OBJS)

re : clean all
