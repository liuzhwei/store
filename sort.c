
//using norm function sort array number as bigger.the array type can be character or integer.
#include <stdio.h>

/** 
* @brief :compare two character numbers and move bigger to the first side.
* 
* @param a: pointer of one number.
* @param b :pointer of another number.
*/
void ch_cmp_char(void * a, void * b)
{
	char i;

	if(*((char *)a) < *((char *)b))
	{
		i = *((char *)a);
		*((char *)a) = *((char *)b);
		*((char *)b) = i;
	}
}
/** 
* @brief compare two integer numbers and move bigger to the first side too.
* 
* @param a:pointer of one number.
* @param b: pointer of another number.
*/
void ch_cmp_int(void * a, void * b)
{
	int i;

	if(*((int *)a) < *((int *)b))
	{
		i = *((int *)a);
		*((int *)a) = *((int *)b);
		*((int *)b) = i;
	}
}
/** 
* @brief :this is norm function,using to sort array number of character or integer.
* 
* @param a:name and address of the array.
* @param len:the lenth of array.
* @param size:how much byte need of typr of the array element 
* @param fun: call function through the function pointer.
*/
void sort(void * a, int len, int size, void (*fun)(void *, void *))
{
	int i, j;
	for (i = len; i > 0; i--) 
	{
		for(j = 0; j < i - 1; j++)
		{
			fun(a+j*size, a+(j+1)*size);
		}
	}
	
}

int main(int argc, const char *argv[])
{
	int a[5] = {1,0,9,5,3};
	char b[15] = {"abzdefwvetpouy"};
	int i;

	sort(a,5,4,ch_cmp_int);
	for (i = 0; i < 5; i++) 
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
	sort(b,14,1,ch_cmp_char);
	for (i = 0; i < 14; i++) 
	{
		printf("%c  ",b[i]);
	}
	printf("\n");

	return 0;
}
