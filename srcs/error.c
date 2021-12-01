#include "so_long.h"

void	my_error(char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(1);
}
