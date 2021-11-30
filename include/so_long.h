#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <stdlib.h>
# include "mlx.h"
# include "libft.h"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_DESTROY_NOTIFY 17
# define NO_EVENT_MASK 0L

# define KEY_ESC 0xff1b


typedef enum	e_map
{
	TILE_SIZE = 64,
	ROW = 5,
	COL = 5,
	WIDTH = COL * TILE_SIZE,
	HEIGHT = ROW * TILE_SIZE,
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

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_img		imgs[3];
	int			map[ROW][COL];
}				t_game;

void	game_init(t_game *game);
void	window_init(t_game *game);
void	img_init(t_game *game);

int		click_cross_mark(int key, t_game *game);
int		deal_key(int key, t_game *game);
int		render_next_frame(t_game *game);

#endif
