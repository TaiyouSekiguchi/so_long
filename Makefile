SO_LONG			=	so_long
SRCS			=	main.c\
					init.c\
					click_cross_mark.c\
					deal_key.c\
					render_next_frame.c\
					get_next_line.c\
					get_next_line_utils.c\
					error.c\
					map_create.c\
					map_check.c\
					read_file.c

OBJS			=	$(SRCS:.c=.o)

CC				=	gcc
#CFLAGS			=	-Wall -Wextra -Werror
INCLUDE			=	-I./include -I/usr/include -I./mlx_linux
#LIBFT			=	-Llibft -lft
MINI			=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
LIBFT			=	-Llibft -lft
RM				=	rm -f

.PHONY			:	all clean fclean re

vpath %.c srcs
vpath %.h include

all				:	$(SO_LONG)

$(SO_LONG)		:	$(OBJS)
					make -C libft
					$(CC) $(OBJS) $(MINI) $(LIBFT) -o $@

%.o				:	%.c
					$(CC) $(INCLUDE) -O3 -c $< -o $@

clean			:
#					make clean -C libft
					$(RM) $(OBJS)

fclean			:
#					make fclean -C libft
					$(RM) $(OBJS) $(SO_LONG) 

re				:	fclean all
