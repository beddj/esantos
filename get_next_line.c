#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "/nfs/2016/e/esantos/42/libft/libft.h"

#define BUFF_SIZE 32
int ft_linenum(char *str);
int get_next_line(const int fd, char **line);

int     main(void)
{
	char  *line;
	int   fd;

	if ((fd = open("file.txt", O_RDONLY)) == -1)
		return (-1);
	while(get_next_line(fd, &line) != 0)
	{
		printf("%s\n", line);
		free(line);
	}
	if (close(fd) == -1)
		return (-1);
	return (0);
}


int get_next_line(const int fd, char **line)
{
	int gotten;
	static char buffer[BUFF_SIZE];
	static char *pointer;
	char *new;

	pointer = ft_strchr(buffer, '\n');
		while((gotten = read(fd,buffer, BUFF_SIZE)) != 0)
		{
			if(gotten > 0)
			{
			buffer[gotten] = '\0';
			new = ft_strjoin(*line, buffer);
			*line = new;
			}
			if(gotten == 0 )
			{
				pointer = ft_strchr(new, '\0');
				if(pointer == *line)
				{
					return (0);
				}
			}
			if(gotten < 0)
			{
				return (0);
			}
			else
				pointer = ft_strchr(new, '\n');
		}
	*line = ft_strncpy(new,*line, pointer - new);
	if(line == NULL)
		return (0);
	pointer = ft_strdup(pointer + 1);
//	free(new);
		new = pointer;
	return (1);
}
