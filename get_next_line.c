#include "get_next_line.h"

static char *leftover;

int	find_eol(char *line)
{
	int	index;

	index = 0;
	while (line[index] != '\n' && line[index] != '\0')
		index++;
	if (line[index] == '\n')
		return (index);
	else
		return (-1);
}

int	get_next_char(int fd, char	*ptr, size_t *counter)
{
	counter += read(fd, ptr, 1);
	if (ptr[*counter] != '\n')
		return (1);
	else
		return (0);
}

char	*get_next_line(int fd)
{
	char	ptr[BUFFER_SIZE + 1];
	size_t	counter;
	int		eol;

	counter = read(fd, ptr, BUFFER_SIZE);
	if (counter < 0)
		return (NULL);
	else if (counter == 0)
		return ("");
	eol = find_eol(ptr);
	
	while (counter < BUFFER_SIZE)
	{
		if (eol)
			get_next_char(fd, leftover, &counter);
		else
			get_next_char(fd, ptr, &counter);
	}
}
