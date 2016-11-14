#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "../42/libft/esantos2/libft.h"

#define BUFF_SIZE 32
char buffer[BUFF_SIZE];
int set;
char *line;

int ft_linenum(char *str);
int get_next_line(const int fd, char **line);

int     main(void)
{
	char  *line;
	int   fd;

	if ((fd = open("file.txt", O_RDONLY)) == -1)
		return (-1);
	if (get_next_line(fd, &line) != 0)
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
	extern int set;

	mark = 0;
	i = 0;
//	printf("%s\n", buffer);
	if(*buffer == '\0') 
	{
		while((gotten = read(fd,buffer, BUFF_SIZE)) != 0)
		{
			buffer[gotten] = '\0';
		}
	}
	mark = ft_linenum(buffer + set);
	set = mark + 1;
	*line = (char*)malloc((sizeof(char) * mark) + 1);
	ft_strncpy(*line, buffer, mark);
	//**line = buffer[set];
	if(*line == '\0')
		return (0);
	else
		return (1);
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
