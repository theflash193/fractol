# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/14 11:01:22 by grass-kw          #+#    #+#              #
#    Updated: 2015/12/07 18:47:37 by grass-kw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = fractol

HEAD = ./libft

LIBX = libx/

FMLX	= -framework OpenGL -framework AppKit -lmlx

IFLAGS = -I . -I ./libft/includes -I ./$(LIBX)

LIB = ./libft/libft.a

FLAGS =

SRC = main.c event.c mlx_image_tools.c algorithm.c new_color.c julia.c parser.c \
	ft_error.c zoom.c move.c mandelbrot.c sierpinski.c motion.c \
	color_utils.c bresenham.c utils.c white_screen.c \
	draw_recursive_sub_triangle.c

OBJ = $(SRC:.c=.o)

RM = rm -rf

all: libft $(NAME)

libft:
	make -C $(HEAD)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIB) -o $(NAME) -L $(LIBX) -framework OpenGL -framework AppKit -lmlx

%.o: %.c
	$(CC) $(FLAGS) $(IFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(HEAD)
re: fclean all

gdb: $(OBJ)
	$(CC) $(OBJ) $(LIB) -o $(NAME) -L/usr/X11/lib -lmlx -lXext -lX11
	gdb $(NAME2) -w

.PHONY: all libft clean fclean re gdb
