# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 11:10:47 by elehtora          #+#    #+#              #
#    Updated: 2022/06/19 20:02:04 by elehtora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### VARIABLES ###

ROOT		:= /home/elehtora/printf
BIN			:= libftprintf.a

SRC			:= \
			  ft_printf.c
SRCDIR		:= sources

OBJ			:= $(SRCDIR)/$(SRC:.c=.o)
OBJDIR		:= objects

TESTDIR		:= tests
TESTSRC		:= testmain.c
TESTBIN		:= printf

INCL		:= includes

LIB			:= ftprintf
LIBDIR		:= lib

CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra
RM			:= /bin/rm -rf


### RULES ###
.PHONY : test clean fclean re

all : $(BIN)

$(BIN) : $(OBJ)
	ar -rcs $@ $<

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCL) -c -o $@ $<

$(OBJDIR) :
	-mkdir $(OBJDIR)

test : $(BIN)
	$(CC) $(CFLAGS) -L$(LIBDIR) -l$(LIB) -o $(TESTBIN)

clean :
	$(RM) $(OBJDIR) *.dSYM

fclean : clean
	$(RM) $(BIN)

re : fclean all
