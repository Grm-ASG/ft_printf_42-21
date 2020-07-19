# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/19 10:09:16 by imedgar           #+#    #+#              #
#    Updated: 2020/07/19 19:21:32 by imedgar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
LIBFT	=	./libft/libft.a

SRC		=	ft_printf.c		\
			ft_putchars.c	\
			ft_formchar.c	\
			ft_formstr.c	\
			ft_formadr.c	\
			ft_formnbr.c	\
			ft_sub_func.c

LIB_SRC	=	ft_atoi.c			\
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

LIB_HED	=	./libft/libft.h

OBJ		=	$(SRC:c=o)
HEADER	=	ft_printf.h

RED		=	\033[31m
GREEN	=	\033[32m
DEF		=	\033[0m
SIDE	=	\/

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f
AR		=	ar rcs

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@cp $(LIBFT) ./$(NAME)
	@$(AR) $(NAME) $(OBJ)
	@echo "\v$(GREEN)$(SIDE)\t\t $(NAME) CREATED \t\t$(SIDE)$(DEF)"

%.o: %.c $(HEADER)
	@echo "$(GREEN)$(SIDE)\t\t CREATED $@ \t\t$(SIDE)$(DEF)"
	@$(CC) $(CFLAGS) -I . -c $< -o $@

$(LIBFT): $(addprefix ./libft/, $(LIB_SRC:c=o)) $(LIB_HED)
	@make -C ./libft

clean:
	@make -C ./libft clean
	@echo "$(RED)$(SIDE)\t\t ERASE OBJ FILES \t\t$(SIDE)$(DEF)"
	@$(RM) $(OBJ) $(OBJBNS)

fclean:
	@make -C ./libft fclean
	@echo "$(RED)$(SIDE)\t\t ERASE OBJ FILES \t\t$(SIDE)$(DEF)"
	@$(RM) $(OBJ) $(OBJBNS)
	@echo "$(RED)$(SIDE)\t\t ERASE $(NAME) \t\t$(SIDE)$(DEF)"
	@$(RM) $(NAME)

re: fclean all
