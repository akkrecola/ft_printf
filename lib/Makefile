# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 15:27:40 by elehtora          #+#    #+#              #
#    Updated: 2022/06/19 21:23:39 by elehtora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES

NAME = libft.a

SRCS		=	ft_atoi.c			\
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
				ft_striter.c		\
				ft_striteri.c		\
				ft_strjoin.c		\
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
				ft_strsep.c			\
				ft_strsplit.c		\
				ft_strstr.c			\
				ft_strsub.c			\
				ft_strtrim.c		\
				ft_nat_sqrt.c		\
				ft_tolower.c		\
				ft_toupper.c

OBJS = $(SRCS:.c=.o)

CC=clang
CFLAGS = -Wall -Wextra -Werror
LIB=ar rcs
RM=/bin/rm -f

# RULES
.PHONY: all objmessage clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "Linking as library \033[1;32m$(NAME)...\033[0m"
	@$(LIB) $(NAME) $(OBJS)

%.o : %.c
	@echo "Creating object file:\t\033[1;32m$(<:.c=.o)\033[0m"
	@$(CC) $(CFLAGS) -c $<

clean :
	@echo "\033[1;32mCleaning object files.\033[0m"
	@$(RM) $(OBJS)

fclean : clean
	@echo "\033[1;32mCleaning $(NAME)...\033[0m"
	@$(RM) $(NAME)

re : fclean all
