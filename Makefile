SO_LONG			=	so_long
SRCS			=	so_long_main.c
OBJS			=	$(SRCS:.c=.o)

CC				=	gcc
#CFLAGS			=	-Wall -Wextra -Werror
INCLUDE			=	-I./include -I/usr/include -I./mlx_linux
#LIBFT			=	-Llibft -lft
MINI			=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

RM				=	rm -f

.PHONY			:	all clean fclean re

#vpath %.c srcs
#vpath %.h include

all				:	$(SO_LONG)

$(SO_LONG)		:	$(OBJS)
#					make -C libft
					$(CC) $(OBJS) $(MINI) -o $@

%.o				:	%.c
					$(CC) $(INCLUDE) -O3 -c $< -o $@

clean			:
#					make clean -C libft
					$(RM) $(OBJS)

fclean			:
#					make fclean -C libft
					$(RM) $(OBJS) $(SO_LONG) 

re				:	fclean all
