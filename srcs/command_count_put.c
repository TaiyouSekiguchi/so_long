#include "so_long.h"

void	command_count_put(int command_count)
{
	ft_putstr_fd("command count:", STDOUT_FILENO);
	ft_putnbr_fd(command_count, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}
