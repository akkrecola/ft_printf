# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 11:10:47 by elehtora          #+#    #+#              #
#    Updated: 2022/09/24 22:30:48 by elehtora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### VARIABLES ###

# Target build executable
NAME		:= libftprintf.a

# Name to feed as library path for user (ftprintf)
BIN_LIB		:= $(subst lib,,$(basename $(NAME)))


SRCS		:= ft_printf.c \
			   integer.c \
			   chars.c \
			   float.c \
			   hex.c \
			   modifiers.c \
			   flags.c
SRCDIR		:= sources

LIBFT_DIR	:= libft
LIBFT		:= $(addprefix $(LIBFT_DIR), libft.a)
LIBFT_OBJS	= $(shell find $(LIBFT_DIR) -type f -regex '.*/*.o')
OBJDIR		:= objects
OBJS		:= $(SRCS:.c=.o)
OBJS		:= $(addprefix $(OBJDIR)/,$(OBJS))

INCL		:= -Iincludes -I$(LIBFT_DIR)

# The libft library is included from ./lib (see header)

CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra -g
RM			:= /bin/rm -rf


### RULES ###
.PHONY : build libft test clean fclean re debug flags

all : $(NAME)

$(NAME) : $(OBJDIR) $(LIBFT) $(OBJS)
	@ar -rcs $@ $(OBJS) $(LIBFT_OBJS)
	@echo "Library archive $(NAME) created successfully."

$(OBJDIR) :
	mkdir -p $(@)

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@echo "Creating object file:\t\033[1;32m$(notdir $(<:.c=.o))\033[0m"
	@$(CC) $(CFLAGS) $(INCL) -c $< -o $@


clean :
	@$(RM) $(OBJDIR) *.dSYM
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Cleaned object files."

fclean : clean
	$(RM) $(NAME) $(TEST_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "Cleaned build executables."

re : fclean all


# Testing utilities
TEST_DIR	:= tests
TEST_SRCS	:= float_test2.c
TEST_SRCS	:= $(addprefix $(TEST_DIR)/,$(TEST_SRCS))
TEST_INCL	:= -I$(TEST_DIR)
TEST_NAME	:= printf.test

test : all
	$(CC) -g $(TEST_SRCS) $(INCL) $(TEST_INCL) \
		-L. -l$(BIN_LIB) -o $(TEST_NAME)
