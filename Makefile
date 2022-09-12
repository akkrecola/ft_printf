# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 11:10:47 by elehtora          #+#    #+#              #
#    Updated: 2022/09/13 01:44:50 by elehtora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### VARIABLES ###

# Target build executable
NAME		:= libftprintf.a

# Name to feed as library path for user (ftprintf)
BIN_LIB		:= $(subst lib,,$(basename $(NAME)))

LIBDIR		:= lib

SRCS		:= test.c # TODO Placeholder source function
SRCDIR		:= sources

LIBFT_SRCS	:= $(notdir $(wildcard $(LIBDIR)/*.c))

OBJDIR		:= objects
OBJS		:= $(SRCS:.c=.o) $(LIBFT_SRCS:.c=.o)
OBJS		:= $(addprefix $(OBJDIR)/,$(OBJS))
# $(info on $(OBJS))

INCL		:= -Iincludes -Ilib

# The libft library is included from ./lib (see header)

CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra
RM			:= /bin/rm -rf


### RULES ###
.PHONY : build test clean fclean re

all : build $(NAME)

build :
	@mkdir -p $(OBJDIR)
	@$(MAKE) -C $(LIBDIR)
	@echo 'Libft objects compiled successfully.'

$(NAME) : $(OBJS)
	@ar -rcs $@ $^
	@echo "Library archive $(NAME) created successfully."

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@echo "Creating object file:\t\033[1;32m$(notdir $(<:.c=.o))\033[0m"
	@$(CC) $(CFLAGS) $(INCL) -c $< -o $@

clean :
	@$(RM) $(OBJDIR) *.dSYM
	@echo "Cleaned object files."

fclean : clean
	@$(RM) $(NAME) $(TEST_NAME)
	@echo "Cleaned build executables."

re : fclean all


# Testing utilities
TEST_DIR	:= tests
TEST_SRCS	:= testmain.c
TEST_SRCS	:= $(addprefix $(TEST_DIR)/,$(TEST_SRCS))
TEST_NAME	:= printf.out

test : all
	$(CC) $(CFLAGS) $(TEST_SRCS) $(INCL) -L. -l$(BIN_LIB) -o $(TEST_NAME)
