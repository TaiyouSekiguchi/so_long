#include "so_long.h"

void	my_error(char *msg)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(1);
}

void	printf_error(void)
{
	printf("Error\n%m\n");
	exit(1);
}
