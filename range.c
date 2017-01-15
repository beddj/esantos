#include <stdio.h>

#include <stdlib.h>

int			*ft_range(int start, int end)
{
	int i;
	int len;
	int *ret;

	if(start < end)
	ret = (int*)malloc(sizeof(int) *(start - end));
	else
	ret = (int*)malloc(sizeof(int) *(end - start + 1));


	while(start != end)
	{
		ret[i++] = start;
		start += (start > end) ? -1 : 1;
	}
	ret[i] = start;
	for(i = 0;i < len; i++)
		printf("%d\n", ret[i]);

	return (ret);
}
int main ()
{
	ft_range(0, 5);
	return (0);
}
