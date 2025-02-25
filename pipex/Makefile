# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/21 13:58:40 by emilgarc          #+#    #+#              #
#    Updated: 2025/02/24 15:09:33 by emilgarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Source
SOURCES = src/pipex.c src/utils.c 
OBJECTS = ${SOURCES:.c=.o}
LIBFT_DIR	= ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Headers
HEADER = src/pipex.h
INCLUDES = -I./src -I./libft -I.

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -L$(LIBFT_DIR) -lft -o $(NAME)
	
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJECTS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
