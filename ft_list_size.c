
typedef struct s_list
{
	struct s_list *next;
	void *data;
} t_list;

int ft_list_size(t_list *begin_list)
{
	t_list *start;
	int i;

	i = 0;
	start = begin_list;
	while(start != NULL)
		i++;
	start = start->next;

	return (i);
}
