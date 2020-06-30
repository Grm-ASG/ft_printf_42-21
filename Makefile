# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/19 10:09:16 by imedgar           #+#    #+#              #
#    Updated: 2020/05/19 11:12:00 by imedgar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
LIBFT	=	./libft/libft.a

SRC		=	ft_printf.c		\
			ft_formchar.c	\
			ft_formstr.c
OBJ		=	$(SRC:c=o)
HEADER	=	ft_printf.h

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f
AR		=	ar rcs

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) ./$(NAME)
	$(AR) $(NAME) $(OBJ)

$(LIBFT):
	make -C ./libft

clean:
	make -C ./libft clean
	$(RM) $(OBJ) $(OBJBNS)

fclean: clean
	make -C ./libft fclean
	$(RM) $(NAME)

re: fclean all
