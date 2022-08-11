# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 14:35:23 by flee              #+#    #+#              #
#    Updated: 2022/08/10 10:23:20 by flee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isdigit.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c\
		ft_memset.c \
		ft_strchr.c \
		ft_split.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_itoa.c \
		ft_putchar_fd.c\
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strmapi.c \
		ft_substr.c	\
		ft_free_tab.c \
		ft_size.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_poptab.c


SRCBONUS =	ft_lstnew.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \

OBJS = $(SRC:.c=.o)

OBJSBONUS = $(SRCBONUS:.c=.o)

all:        $(NAME)

$(NAME):    $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus:    $(OBJSBONUS)
	ar rc $(NAME) $(OBJSBONUS)
.c.o:
		gcc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)
clean:
		/bin/rm -f $(OBJS)    $(OBJSBONUS)

fclean:	clean
	/bin/rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
