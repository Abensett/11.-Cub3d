# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abensett <abensett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 19:20:13 by flee              #+#    #+#              #
#    Updated: 2022/08/10 11:44:45 by abensett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= cub3D

SRCS= main.c get_file.c parse.c square_map.c game_loop.c game_img.c game_raycasting.c \
		game_display.c game_move.c game_move2.c parse_wall.c parse_map.c game_utils.c game_utils2.c clean.c

SRCS_BONUS= main.c get_file.c parse.c square_map.c game_loop.c game_img.c game_raycasting.c minimap.c draw_sky.c \
		game_display.c game_move.c game_move2.c parse_wall.c parse_map.c game_utils.c game_utils2.c clean.c \
		life_bar.c gameoverorwon.c sprites.c
OBJS			=	${addprefix srcs/,${SRCS:.c=.o}}

OBJS_BONUS		=	${addprefix srcs/bonus/,${SRCS_BONUS:.c=.o}}

LD_FLAGS		=	-L libft -L mlx

MLX_FLAGS		=	-lm -lmlx -lXext -lX11

HEAD			=	-I includes -I libft -I mlx

CC				=	clang

CFLAGS			=	-Wall -Werror -Wextra

.c.o			:
					@${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME)			:	${OBJS}
					@make -C libft
					@make -C mlx
					@${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} -o ${NAME} -lft ${MLX_FLAGS}

bonus			:	${OBJS_BONUS}
					@make -C libft
					@make -C mlx
					@${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS_BONUS} -o "Cub3D_bonus" -lft ${MLX_FLAGS}

all				:	${NAME}


clean			:
					make clean -C libft
					make clean -C mlx
					@rm -rf ${OBJS}
					@rm -rf ${OBJS_BONUS}


fclean			:	clean
					make fclean -C libft
					@rm -rf ${NAME}
					@rm -rf "Cub3D_bonus"


re				:	fclean all

.PHONY			:	all clean fclean re
