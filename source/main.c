#include <stdlib.h>
#include <print_memory.h>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("Usage: print_memory <SIZE>\n");
		return (EXIT_ERROR);
	}
	unsigned long long size = strtoull(av[1], 0, 0);
	print_memory((void*)main, size);
	return (EXIT_SUCCESS);
}
