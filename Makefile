#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okuznets <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/26 15:48:43 by okuznets          #+#    #+#              #
#    Updated: 2018/09/26 15:48:45 by okuznets         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INC = Includes

SDIR = Srcs

SRCS = 	bresenhem.c\
		change_angle.c\
		count_projection.c\
		draw_image.c\
		key_hook.c\
		main.c\
		put_image.c\
		read_map.c\
		rotate.c\
		zoom.c\
		errors.c\

HEADERS = fdf.h

ODIR = Objects

OBJ = $(SRCS:.c=.o)

OBJ_R = $(OBJ:%.o=$(ODIR)/%.o)

all : $(NAME)

$(NAME) : $(ODIR)/ $(OBJ_R)
	make -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_R) ./libft/libft.a  -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

.PHONY: clean fclean re

clean :
	rm -f $(OBJ_R)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

norm:
	make norm -C libft
	norminette $(SRCS:%.c=$(SDIR)/%.c) $(HEADERS:%.h=$(INC)/%.h)

add:
	make add -C ./libft
	git add $(SRCS:%.c=$(SDIR)/%.c) $(HEADERS:%.h=$(INC)/%.h) .gitignore Makefile CMakeLists.txt author

test1: $(NAME)
	./$(NAME)

$(ODIR)/ :
	mkdir -p $@

$(ODIR)/%.o : $(SDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I ./libft -I $(INC)
