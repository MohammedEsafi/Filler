# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/14 12:23:57 by mesafi            #+#    #+#              #
#    Updated: 2019/11/22 23:08:56 by mesafi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Usage:
# make			# compile all binary
# make clean	# remove all binaries and objects
# make fclean	# remove created library
# make re		# Get recompiled

# Standard variables
LIBFT	= libft.a
NAME	= viSion
OBJS	= vision.o \
		helpers/drawing.o \
		helpers/reader.o \
		helpers/gang.o \
		helpers/probing.o \
		helpers/top_bar.o
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
MINI_LIB_FLAGS = -lm -lmlx -framework OpenGL -framework AppKit

# Colors
BLACK	= \033[30m
RED		= \033[31m
GREEN	= \033[32m
YELLOW	= \033[93m
BLUE	= \033[34m
MAGENTA	= \033[35m
CYAN	= \033[36m
WHITE	= \033[37m
RESET	= \033[0m

# Start rules
all: build $(NAME)

build:
	@if [ ! -f $(NAME) ] ; then \
		echo "⇾ building $(NAME)..." ; \
	fi;

$(NAME): $(OBJS) vision.h
	@if [ ! -f $(NAME) ] ; then \
		echo "⇾ $(NAME) $(GREEN)done!$(RESET)" ; \
	fi;
	@$(CC) $(CFLAG) $(OBJS) ../libft/$(LIBFT) $(MINI_LIB_FLAGS) -o $(NAME)

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@
	@if [[ -f $(NAME) ]] ; then \
		echo "⇾ $@ $(GREEN)updated$(RESET)" ; \
	fi;

clean:
	@rm -f $(OBJS)
	@echo "⇾ $(NAME) $(RED)cleaned$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "⇾ $(NAME) $(RED)deleted$(RESET)"

re: fclean all
