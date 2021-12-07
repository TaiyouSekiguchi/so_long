#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

# define DESTROY_NOTIFY 17
# define KEY_PRESS 2
# define MAP_NOTIFY 19
# define NO_EVENT_MASK 0L

# define KEY_ESC 0xff1b
# define KEY_W 0x77
# define KEY_S 0x73
# define KEY_A 0x61
# define KEY_D 0x64

# define TILE_SIZE 32

# define GRASS			"./texture/grass.xpm"
# define FLOWER			"./texture/flower.xpm"
# define TREASURE		"./texture/treasure.xpm"
# define GOAL			"./texture/goal.xpm"
# define HERO			"./texture/hero.xpm"

typedef enum e_mapinfo
{
	EMPTY = 0,
	WALL,
	COLLECTIBLE,
	EXIT,
	PLAYER,
}			t_mapinfo;

typedef struct s_map
{
	int			**map;
	int			row;
	int			col;
}				t_map;

typedef struct	s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct	s_img
{
	void		*img;
	int			width;
	int			height;
}				t_img;

typedef struct	s_window
{
	int			row;
	int			col;
}				t_window;

typedef struct	s_game
{
	void			*mlx;
	void			*win;
	t_map			map;
	t_player		player;
	t_img			img;
	t_img			texs[5];
	t_window		window;
	int				c_cnt;
}				t_game;

int		extension_check(char *file_path);
void	game_init(t_game *game);
void	window_init(t_game *game);
void	img_init(t_img texs[], void *mlx);
int		game_exit(t_game *game);
int		deal_key(int key, t_game *game);
int		render_next_frame(t_game *game);
void	my_error(char *msg);
void	printf_error(void);
void	map_create(t_map *map, t_list *list);
void	map_put(t_map *map);
void	map_check(t_game *game, int c_cnt, int e_cnt, int p_cnt);
void	read_file(t_list **list, char *file_path);
void	command_count_put(void);
void	clear_check(int clear, int *finish_position);
void	get_player(t_game *game);

#endif
