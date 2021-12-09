# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 17:08:25 by tsekiguc          #+#    #+#              #
#    Updated: 2021/12/09 15:26:34 by tsekiguc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SO_LONG			=	so_long
SRCS			=	main.c\
					window_init.c\
					img_init.c\
					game_exit.c\
					deal_key.c\
					render_next_frame.c\
					get_next_line.c\
					get_next_line_utils.c\
					error.c\
					map_create.c\
					map_check.c\
					map_put.c\
					read_file.c\
					command_count_put.c\
					extension_check.c\
					clear_check.c\
					get_player.c
OBJS			=	$(SRCS:.c=.o)

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
INCLUDE			=	-I./include -I/usr/include -I./mlx_linux
MINI			=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
LIBFT			=	-Llibft -lft
RM				=	rm -f

.PHONY			:	all clean fclean re

vpath %.c srcs
vpath %.h include

all				:	$(SO_LONG)

$(SO_LONG)		:	$(OBJS)
					make -C mlx_linux
					make -C libft
					$(CC) $(CFLAGS) $(OBJS) $(MINI) $(LIBFT) -o $@

%.o				:	%.c
					$(CC) $(CFLAGS) $(INCLUDE) -O3 -c $< -o $@

clean			:
					make clean -C libft
					$(RM) $(OBJS)

fclean			:
					make fclean -C libft
					$(RM) $(OBJS) $(SO_LONG) 

re				:	fclean all
