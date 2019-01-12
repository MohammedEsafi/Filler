# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/14 12:23:57 by mesafi            #+#    #+#              #
#    Updated: 2019/11/22 22:00:27 by mesafi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Usage:
# make			# compile all binary
# make clean	# remove all binaries and objects
# make fclean	# remove created library
# make re		# Get recompiled

# Standard variables
LIBFT	= libft.a
VISION	= viSion
NAME	= mesafi.filler
OBJS	= filler.o \
		helpers/map_reader.o \
		helpers/player_concerned.o \
		helpers/obtain_token.o \
		helpers/make_heatmap.o \
		helpers/find_out.o \
		helpers/error_handler.o
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

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

$(NAME): $(OBJS) filler.h
	@make -s -C libft/
	@make -s -C vision/
	@if [ ! -f $(NAME) ] ; then \
		echo "⇾ $(NAME) $(GREEN)done!$(RESET)" ; \
	fi;
	@$(CC) $(CFLAG) $(OBJS) libft/$(LIBFT) -o $(NAME)

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@
	@if [[ -f $(NAME) ]] ; then \
		echo "⇾ $@ $(GREEN)updated$(RESET)" ; \
	fi;

clean:
	@make clean -s -C libft/
	@make clean -s -C vision/
	@rm -f $(OBJS)
	@echo "⇾ $(NAME) $(RED)cleaned$(RESET)"

fclean: clean
	@rm -f libft/$(LIBFT)
	@rm -f vision/$(VISION)
	@rm -f $(NAME)
	@echo "⇾ $(LIBFT) $(RED)deleted$(RESET)"
	@echo "⇾ $(VISION) $(RED)deleted$(RESET)"
	@echo "⇾ $(NAME) $(RED)deleted$(RESET)"

re: fclean all
