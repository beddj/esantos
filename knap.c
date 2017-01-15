#include <stdio.h>
#include <time.h>


int knap(int cap);

typedef struct Item {
	char name;
	int size;
	int val;
} Item;

int main(void)
{
clock_t begin = clock();

printf("%d\n", knap(13));

clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("%f\n",time_spent);


return (0);
}

int knap(int cap)
{
	int i;
	int space;
	int max;
	int t;

	Item items[] = {
		{'A',3,4},{'B',4,5}, {'C',7, 10}, {'D',8,11}, {'E',9,13}, {'F', 5,12},{'B',4,5},{'B',4,5},{'B',4,5},{'B',4,5},{'B',4,5}
	}; 


	i = 0;
	max = 0;
	for(i = 0,max = 0;i < 11;i++)
	
		if((space = cap - items[i].size) >= 0)
			if((t = knap(space) + items[i].val) > max)
				max = t;
		return (max);
}
