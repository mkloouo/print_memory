#include <print_memory.h>

void	*print_memory(void *addr, unsigned long size)
{
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned char const *memory;

	memory  = (unsigned char const *)addr;
	while (i < size)
	{
		print_addr(addr + i);
		ft_putstr(": ");
		while (j < BYTES_STEP && (i + j) < size)
		{
			if (j > 0 && (j % BYTES_ALIGN) == 0)
				ft_putchar(' ');
			ft_putchar(PREV_LAST_HEX(memory[i + j]));
			ft_putchar(LAST_HEX(memory[i + j]));
			++j;
		}
		while (j <= BYTES_STEP)
		{
			if (j > 0 && j < BYTES_STEP &&
			    (j % BYTES_ALIGN) == 0)
				ft_putchar(' ');
			ft_putstr("  ");
			++j;
		}
		j = 0;
		while (j < BYTES_STEP && (i + j) < size)
			ft_putanychar(memory[i + j++]);
		while (j < BYTES_STEP)
		{
			ft_putchar(' ');
			++j;
		}
		i += j;
		j = 0;
		ft_putchar('\n');
	}
	return (addr);
}

void	print_addr(void *addr)
{
	unsigned int i;
	char tab[BYTES_STEP + 1];
	unsigned long long addr_number;

	i = 0;
	tab[BYTES_STEP] = 0;
	addr_number = (unsigned long long)addr;
	while (i < BYTES_STEP)
	{
		tab[BYTES_STEP - i - 1] = LAST_HEX(addr_number);
		addr_number /= HEXTAB_SIZE;
		++i;
	}
	ft_putstr(tab);
}

size_t	ft_strlen(char const *str)
{
	size_t len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		++len;
	return (len);
}

void	ft_putstr(char const *str)
{
	size_t len = ft_strlen(str);
	write(STDOUT_FILENO, str, len);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putanychar(char c)
{
	if (ft_isprint(c))
		ft_putchar(c);
	else
		ft_putchar('.');
}

int	ft_isprint(int c)
{
	return (c > 31 && c < 127);
}
