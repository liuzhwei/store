
//using norm function compare two integer or character date, printing the bigger// one.

#include <stdio.h>

/** 
* @brief compare two integer data.
* 
* @param a :a is a pointer which point to one of the data.
* @param b :same as a.
* 
* @return :return positive number or negetive number from a or b is bigger.
*/
int cmp_int(void * a, void * b)
{
	return *((int *)a) - *((int *)b); 
}
/** 
* @brief compare two character data.
* 
* @param a :a is a pointer which point to one of the data.
* @param b :same as a.
* 
* @return :return positive number or negetive number from a or b is bigger.
*/
int cmp_char(void * a, void * b)
{
	return *((char *)a) - *((char *)b);
}
/** 
* @brief :This is the norm function. We can get the bigger number of integer
* and character.
* @param a: a is a array name, we get numbers from it.
* @param len: len is the lenth of array a.
* @param size :size is the type of array. size is 4 of integer and 1 of character.
* @param cmp: the pointer of function. call bach compare functions.
* 
* @return :return a pointer too. pointing to address of bigger number.
*/
void * get_max(void *a, int len, int size, int (*cmp)(void * a, void *b))
{
	char i, *max;

	max=a;
	for(i=0;i<len;i++)
	{
		if(cmp(max,a+size*i) > 0)
		{
			
		}
		else
		{
			max=a+i*size;
		}
	}
	return max;
}
int main(int argc, const char *argv[])
{
	int a[10] = {15,3,5,7,80,6,4,2,0,9};
	//char b[10] = {1,2,3,9,8,7,6,5,4};
	char b[10] = {"abcdzkilj"};
	int i=0;
	char j;

	i=*((int *)get_max(a,10,4,cmp_int));
	printf("%d\n",i);
	j=*((char *)get_max(b,9,1,cmp_char));
	printf("%c\n",j);

	return 0;
}
