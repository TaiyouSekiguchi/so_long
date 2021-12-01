#include "so_long.h"

static size_t	get_col_size(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\n')
		i++;
	return (i);
}

int	map_create(t_map *map, t_list *list)
{
	t_list			*current;
	char			*tmp;
	unsigned int	row;
	int				col;
	int				i;
	int				j;

	current = list;
	map->row = ft_lstsize(current);
	map->col = get_col_size(current->content);
	row = ft_lstsize(current);
	map->map = (int **)malloc(sizeof(int *) * row);
	i = 0;
	while (i < row)
	{
		if (map->col != get_col_size(current->content))
			my_error("map is not recangle");
		map->map[i] = (int *)malloc(sizeof(int) * map->col);
		if (map->map[i] == NULL)
			return (0);
		j = 0;
		tmp = (char *)current->content;
		while (tmp[j] != '\n')
		{
			if (tmp[j] == '0' || tmp[j] == '1')
				map->map[i][j] = tmp[j] - '0';
			else if (tmp[j] == 'C')
				map->map[i][j] = 2;
			else if (tmp[j] == 'E')
				map->map[i][j] = 3;
			else if (tmp[j] == 'P')
				map->map[i][j] = 4;
			else
				my_error("Error\nError Character in map");
			j++;
		}
		current = current->next;
		i++;
	}
	return (1);
}

void	map_put(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			ft_putnbr_fd(map->map[i][j], STDOUT_FILENO);
			ft_putstr_fd(" ", STDOUT_FILENO);
			j++;
		}
		ft_putstr_fd("\n", STDOUT_FILENO);
		i++;
	}
}
