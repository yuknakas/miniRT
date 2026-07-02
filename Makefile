# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/01 11:44:22 by yuknakas          #+#    #+#              #
#    Updated: 2026/07/02 12:33:43 by yuknakas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minirt
CCW		=	cc -Wall -Wextra -Werror -O2

LIBS	=	-Llibft -lgnl -lft -Lminilibx-linux -lmlx -lX11 -lXext -lm

RMFLAG	=	rm -rf

SRC		=	srcs/get_closest.c srcs/main.c srcs/set_pixel.c
COLORS	=	srcs/Color/get_brigtness.c srcs/Color/get_color.c \
			srcs/Color/get_normal.c srcs/Color/get_rgb.c
DISPLAY	=	srcs/Display/clean_display.c srcs/Display/setup_display.c
ELEMENT	=	srcs/Elements/cylinder.c srcs/Elements/cylinder_end.c \
			srcs/Elements/plane.c srcs/Elements/ray_to_pixel.c \
			srcs/Elements/setup_screen.c srcs/Elements/sphere.c
PARSER	=	srcs/Parser/clean.c srcs/Parser/elem_utils.c srcs/Parser/parser.c \
			srcs/Parser/set_element.c srcs/Parser/set_element2.c \
			srcs/Parser/set_vector.c srcs/Parser/utils.c
VECTORS	=	srcs/Vectors/vectors.c srcs/Vectors/vectors2.c

SRCS	=	$(SRC) $(COLORS) $(DISPLAY) $(ELEMENT) $(PARSER) $(VECTORS)
OBJS	=	$(SRCS:srcs/%.c=objs/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) libft -C ./libft
	@$(MAKE) gnl -C ./libft
	@$(CCW) $(OBJS) $(CFLAG) $(LIBS) -o $(NAME)
	@echo "> make minirt executed in current directory"

objs/%.o: srcs/%.c
	mkdir -p $(dir $@)
	@$(CCW) -c $< -o $@

bonus: all

clean:
	@$(MAKE) clean -C ./libft
	@$(RMFLAG) objs
	@echo "> clean executed in current directory"

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RMFLAG) $(NAME)
	@echo "> fclean executed in current directory"

re: fclean all

.PHONY: all bonus re clean fclean