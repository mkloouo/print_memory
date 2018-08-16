#ifndef __PRINT_MEMORY_H__
# define __PRINT_MEMORY_H__

# include <unistd.h>

# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS 1
# endif
# ifndef EXIT_ERROR
#  define EXIT_ERROR 0
# endif

# define HEXTAB "0123456789abcdef"
# define HEXTAB_SIZE 16
# define PREV_LAST_HEX(C) (HEXTAB[(C / HEXTAB_SIZE) % HEXTAB_SIZE])
# define LAST_HEX(C) (HEXTAB[C % HEXTAB_SIZE])

# define BYTES_STEP 16
# define BYTES_ALIGN sizeof(int)

void	*print_memory(void *addr, unsigned long size);
void	print_addr(void *addr);

size_t	ft_strlen(char const *str);
void	ft_putstr(char const *str);

void	ft_putchar(char c);
void	ft_putanychar(char c);

int	ft_isprint(int c);

#endif
