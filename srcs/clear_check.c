#include "so_long.h"

void	clear_check(int clear, int *finish_position)
{
	if (clear == 1)
	{
		*finish_position = EXIT;
		ft_putendl_fd("Teleported to the next map...!!", STDOUT_FILENO);
	}
}
