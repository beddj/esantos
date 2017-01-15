#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include <unistd.h>
#include <string.h>

int ft_list_size(Node_t *start)
{
	int i;
	Node_t *begin;

	begin = start;
	i = 0;
if(begin != NULL)
{
	while(begin != NULL)
	{
		i++;
		begin =begin->next;
	}
}
	return (i);
	
}

int main()
{
	int i;
	Node_t *head;
	Node_t *temp;
	Node_t *temp1;

	temp = (Node_t*)malloc(sizeof(Node_t));

	temp->data = 1;
	temp->next = NULL;

	head = temp;

	temp = (Node_t*)malloc(sizeof(Node_t));
	temp->data = 2;
	temp->next = NULL;
	head->next = temp;
	temp = (Node_t*)malloc(sizeof(Node_t));
	temp->data = 3;
	temp->next = NULL;
	temp1 = head;

	while(temp1->next != NULL)
	{
		temp1 = temp1->next;
	}
	temp1->next = temp;

	

	printf("%d\n", ft_list_size(head));

return (0);

}



