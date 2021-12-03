#include "so_long.h"

static size_t	get_col_size(char *line)
{
	size_t	i;

	if (line == NULL)
		return (0);
	i = 0;
	while (line[i] != '\n')
		i++;
	return (i);
}

static void	get_map_size_and_malloc(t_map *map, t_list *current)
{
	map->row = ft_lstsize(current);
	map->col = get_col_size(current->content);
	map->map = (int **)malloc(sizeof(int *) * map->row);
	if (map->map == NULL)
		my_error("Error\nmalloc error in map_create");
}

static void	col_len_check_and_malloc(t_map *map, t_list *current, int i)
{
	if (map->col != get_col_size(current->content))
		my_error("Error\nmap is not recangle");
	map->map[i] = (int *)malloc(sizeof(int) * map->col);
	if (map->map[i] == NULL)
		my_error("Error\nmalloc error in map_create");
}

static void	char_to_int(char c, int *map)
{
	if (c == '0')
		*map = EMPTY;
	else if (c == '1')
		*map = WALL;
	else if (c == 'C')
		*map = COLLECTIBLE;
	else if (c == 'E')
		*map = EXIT;
	else if (c == 'P')
		*map = PLAYER;
	else
		my_error("Error\nError Character in map");
}

void	map_create(t_map *map, t_list *list)
{
	t_list	*current;
	char	*tmp;
	int		i;
	int		j;

	current = list;
	get_map_size_and_malloc(map, current);
	i = 0;
	while (i < map->row)
	{
		col_len_check_and_malloc(map, current, i);
		j = 0;
		tmp = (char *)current->content;
		while (tmp[j] != '\n')
		{
			char_to_int(tmp[j], &map->map[i][j]);
			j++;
		}
		current = current->next;
		i++;
	}
}
