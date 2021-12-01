#include "so_long.h"

void	read_file(t_list **list, char *file_path)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		my_error("file open error in read_file");

	*list = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_lstadd_back(list, ft_lstnew(line));
		line = get_next_line(fd);
	}
	close(fd);
}
