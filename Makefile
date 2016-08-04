# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/25 13:39:38 by vklaouse          #+#    #+#              #
#    Updated: 2016/01/25 14:00:22 by vklaouse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS = -Wall -Wextra -Werror

CC = gcc

SRC = main.c aff.c stock_fd.c draw.c trace.c utils.c keyboard.c

OBJ = $(SRC:.c=.o)

$(NAME):
	make -C libft/ fclean && make -C libft 
	make -C minilibx_macos/ clean && make -C minilibx_macos
	$(CC) $(FLAGS) $(SRC) -c -I./libft/includes
	$(CC) -o $(NAME) $(OBJ) -L./minilibx_macos -lmlx -framework OpenGL -framework Appkit -L./libft -lft

all: $(NAME)

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	make -C minilibx_macos/ clean

re: fclean all
