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
		col= get_col_size(current->content);
		map->map[i] = (int *)malloc(sizeof(int) * col);
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

void	first_or_last_row_check(int *map, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (map[i] != 1)
			my_error("map is not closed");
		i++;
	}
}

void	first_or_last_col_check(int *map, int col)
{
	if (map[0] != 1 || map[col - 1] != 1)
		my_error("map is not closed");
}

void	count_check(int	c_cnt, int e_cnt, int p_cnt)
{
	if (c_cnt < 1)
		my_error("Error\nno collective");
	if (e_cnt != 1)
		my_error("Error\nexit is not correct");
	if (p_cnt != 1)
		my_error("Error\nplayer is not correct");
}

void	map_check(t_map *map)
{
	int	c_cnt;
	int	e_cnt;
	int	p_cnt;
	int	i;
	int	j;

	c_cnt = 0;
	e_cnt = 0;
	p_cnt = 0;
	i = 0;
	while (i < map->row)
	{
		if (i == 0 || i == map->row - 1)
			first_or_last_row_check(map->map[i], map->col);
		else
		{
			first_or_last_col_check(map->map[i], map->col);
			j = 0;
			while (j < map->col)
			{
				if (map->map[i][j] == 2)
					c_cnt++;
				else if (map->map[i][j] == 3)
					e_cnt++;
				else if (map->map[i][j] == 4)
					p_cnt++;
				j++;
			}
		}
		i++;
	}
	count_check(c_cnt, e_cnt, p_cnt);
}
