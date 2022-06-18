# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 11:10:47 by elehtora          #+#    #+#              #
#    Updated: 2022/06/18 13:30:24 by elehtora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### VARIABLES ###

ROOT		= /home/elehtora/printf
BIN			= libftprintf.a

SRC			= \
			  ft_printf.c
SRCDIR		= sources

OBJ			:= $(SRCDIR/SRC:.o=.c)
OBJDIR		= objects

TESTDIR		= tests
TESTSRC		= testmain.c

INCL		= includes

LIB			= ft
LIBBIN		= libft.a
LIBDIR		= lib

CC			= gcc
$(RM)		= /bin/rm -rf


### RULES ###
.PHONY : clean fclean

all : $(BIN)

$(BIN) : $(OBJ) $(LIBBIN)
	ar -rcs $@ $<

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCL) -c -o $@ $<

$(OBJDIR) :
	-mkdir $(OBJDIR)

$(LIBBIN) :
	cd $(LIBDIR) && $(MAKE) $@ && cd ..

clean :
	$(RM) $(OBJDIR)

fclean : clean
	$(RM) $(BIN)

re : fclean all
