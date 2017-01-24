# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocblande <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 11:51:52 by ocblande          #+#    #+#              #
#    Updated: 2016/12/06 19:17:12 by ocblande         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_toupper.c ft_tolower.c ft_isalnum.c \
	  ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c ft_isprint.c \
	  ft_isupper.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
	  ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
	  ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strlen.c ft_strdup.c \
	  ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c \
	  ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c \
	  ft_strncmp.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
	  ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
	  ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_lstnew.c \
	  ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	  ft_strndup.c ft_tabnew.c ft_tabdel.c

POINTO = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC)
	ar rc $(NAME) $(POINTO)

clean:
		rm -f $(POINTO)
fclean: clean
		rm -f $(NAME)

re: fclean all
