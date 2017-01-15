#include <stdio.h>
#include <string.h>


int query(int x, int y, int *arr);
int add(int x, int y, int *arr);
int total(int *arr, int len);

int main (int argc, char **argv)
{
	int i;
	int result;
	int len;
	int arr[] = {1,2,3,4,5,6,7,8};

	len = sizeof(arr) / sizeof(int);

	//printf("Result:%d\n", query(0,3,arr));
	//add(0,5,arr);
	//printf("Result:%d\n", query(0,3,arr));
	printf("Total:%d\n", total(arr, len));
	return (0);
}

int query(int x, int y, int *arr)
{
	int result;

	result = 0;
	while(x <= y)
	{
		result += arr[x];
		x++;
	}
	return (result);
}

int add(int x, int y, int *arr)
{
	arr[x] = arr[x] + y;
	return (arr[x]);
}

int total(int *arr, int len)
{
		int i;
		int total;

		i = 0;
		total = 0;
	while(i <= len -  1)
	{
		total += arr[i];
		i++;
	}
		return (total);
}
