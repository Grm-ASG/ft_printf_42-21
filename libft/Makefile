# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/03 23:24:43 by imedgar           #+#    #+#              #
#    Updated: 2020/07/19 15:28:37 by imedgar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRC		=	ft_atoi.c			\
			ft_bzero.c			\
			ft_calloc.c			\
			ft_isalnum.c		\
			ft_isalpha.c		\
			ft_isascii.c		\
			ft_isdigit.c		\
			ft_isprint.c		\
			ft_itoa.c			\
			ft_itoa_base.c		\
			ft_memccpy.c		\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_memcpy.c			\
			ft_memmove.c		\
			ft_memset.c			\
			ft_putnbr.c			\
			ft_putchar.c		\
			ft_putstr.c			\
			ft_split.c			\
			ft_strchr.c			\
			ft_strdup.c			\
			ft_strjoin.c		\
			ft_strlcat.c		\
			ft_strlcpy.c		\
			ft_strlen.c			\
			ft_strmapi.c		\
			ft_strncmp.c		\
			ft_strnstr.c		\
			ft_strrchr.c		\
			ft_strtrim.c		\
			ft_substr.c			\
			ft_tolower.c		\
			ft_toupper.c
HEADER	=	libft.h
OBJ		=	$(SRC:c=o)

RED		=	\033[31m
GREEN	=	\033[32m
DEF		=	\033[0m
SIDE	=	\/

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f
AR		=	ar rcs


all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $@ $(OBJ)
	@echo "\v$(GREEN)$(SIDE)\t\t $(NAME) CREATE \t\t$(SIDE)$(DEF)\v"

%.o: %.c $(HEADER)
	@echo "$(GREEN)$(SIDE)\t\t CREATE $@ \t\t$(SIDE)$(DEF)"
	@$(CC) $(CFLAGS) -I . -c $< -o $@

clean:
	@echo "$(RED)$(SIDE)\t\t ERASE OBJ FILES OF $(NAME) \t$(SIDE)$(DEF)"
	@$(RM) $(OBJ) $(OBJBNS)

fclean: clean
	@echo "$(RED)$(SIDE)\t\t ERASE $(NAME) \t\t\t$(SIDE)$(DEF)"
	@$(RM) $(NAME)

re: fclean all
