# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 14:57:32 by yuknakas          #+#    #+#              #
#    Updated: 2025/01/14 14:13:12 by yuknakas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	libft.a

CTYPE		=	ctype/ft_isalnum.c ctype/ft_isalpha.c ctype/ft_isascii.c ctype/ft_isdigit.c \
				ctype/ft_isprint.c ctype/ft_tolower.c ctype/ft_toupper.c
FD			=	fd/ft_putchar_fd.c fd/ft_putendl_fd.c fd/ft_putnbr_fd.c fd/ft_putstr_fd.c
LST			=	lst/ft_lstadd_back_bonus.c lst/ft_lstadd_front_bonus.c lst/ft_lstclear_bonus.c \
				lst/ft_lstdelone_bonus.c lst/ft_lstiter_bonus.c lst/ft_lstlast_bonus.c \
				lst/ft_lstmap_bonus.c lst/ft_lstnew_bonus.c lst/ft_lstsize_bonus.c
MEMORY		=	memory/ft_bzero.c memory/ft_memchr.c memory/ft_memcmp.c memory/ft_memcpy.c \
				memory/ft_memmove.c memory/ft_memset.c
STDLIB		=	stdlib/ft_atoi.c stdlib/ft_calloc.c stdlib/ft_itoa.c
STRING		=	string/ft_split.c string/ft_strchr.c string/ft_strdup.c string/ft_striteri.c \
				string/ft_strjoin.c string/ft_strlcat.c string/ft_strlcpy.c string/ft_strlen.c \
				string/ft_strmapi.c string/ft_strncmp.c string/ft_strnstr.c string/ft_strrchr.c \
				string/ft_strtrim.c string/ft_substr.c

SRCS_MAN	=	$(CTYPE) $(FD) $(MEMORY) $(STDLIB) $(STRING)
SRCS_BON	=	$(LST)
OBJS_MAN	=	$(SRCS_MAN:%.c=%.o)
OBJS_BON	=	$(SRCS_BON:%.c=%.o)
OBJS		=	$(OBJS_MAN) $(OBJS_BON)
BONUS_FLAG	=	.bonus_flag

all: $(NAME)

$(NAME): $(OBJS_MAN)
	@ar rcs $(NAME) $(OBJS_MAN)
	echo "> make all executed"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_FLAG)

$(BONUS_FLAG): $(OBJS_MAN) $(OBJS_BON)
	@ar rcs $(NAME) $(OBJS_BON)
	@touch $(BONUS_FLAG)
	echo "> make bonus executed"

clean:
	@rm -f $(OBJS) $(BONUS_FLAG)
	echo "> make clean executed"

fclean: clean
	@rm -f $(NAME)
	echo "> make fclean executed"

re: fclean all

.PHONY: all bonus clean fclean re