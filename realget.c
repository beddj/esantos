#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "../42/libft/esantos2/libft.h"

#define BUFF_SIZE 32
char buffer[BUFF_SIZE];
char *set;

int ft_linenum(char *str);
int get_next_line(const int fd, char **line);

int     main(void)
{
	char  *line;
	int   fd;

	if ((fd = open("file.txt", O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &line) != 0)
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
	int mark;
	extern char *set;

	i = 0;
	if(buffer[0] != '\0') 
	{
		while((gotten = read(fd,buffer, BUFF_SIZE)) != 0)
		{
			buffer[gotten] = '\0';
		}
	}
//	*buffer = *set;
	mark = ft_linenum(buffer);
	*line = (char*)malloc((sizeof(char) * mark) + 1);
	ft_strncpy(*line, buffer, mark + 1);
	set = &buffer[mark + 1];
	printf("%s\n", buffer);
	if(*line[0] == '\0' || *line[0] == '\n')
		return (1);
	else
		return (0);
}

int ft_linenum(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\n' )
	{
		i++;
	}
	return (i);
}
