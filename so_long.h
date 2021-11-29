#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <stdlib.h>
# include "mlx.h"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

typedef enum	e_map
{
	TILE_SIZE = 64,
	ROW = 4,
	COL = 4,
	WIDTH = COL * TILE_SIZE,
	HEIGHT = ROW * TILE_SIZE,
}				t_map;

typedef	enum	e_key
{
	KEY_ESC = 9,
}				t_key;

typedef struct	s_img
{
	void	*img;
	int		width;
	int		height;
}				t_img;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		map[ROW][COL];
}				t_game;

void	game_init(t_game *game);
void	window_init(t_game *game);

#endif
