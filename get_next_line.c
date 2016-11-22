#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "/nfs/2016/e/esantos/42/libft/libft.h"

#define BUFF_SIZE 32
char buffer[BUFF_SIZE];
char *pointer;
extern char *line;

int ft_linenum(char *str);
int get_next_line(const int fd, char **line);

int     main(void)
{
	char  *line;
	int   fd;

	if ((fd = open("file.txt", O_RDONLY)) == -1)
		return (-1);
	if(get_next_line(fd, &line) != 0)
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
	extern char buffer[BUFF_SIZE];
	int i;
	extern char *pointer;
	char *new;

	i = 0;
	pointer = ft_strchr(buffer, '\n');
	while((gotten = read(fd,buffer, BUFF_SIZE)) != 0)
	{
		buffer[gotten] = '\0';
		new = ft_strjoin(*line, buffer);
		*line = new;
	}
	if( gotten == 0 )
	{
		pointer = ft_strchr(new, '\0');
		if(pointer == *line)
			return (0);
	}
	else if(gotten < 0)
	{
		return (0);
	}
	else
		pointer = ft_strchr(new, '\n');

	*line = ft_strncpy(new,*line, pointer - new);
	if(line == NULL)
		return (0);
	pointer = ft_strdup(pointer + 1);
//	new = pointer;
	return (1);

}
