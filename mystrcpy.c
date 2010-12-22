#include <stdio.h>
#define M 3
#define N 10

struct people_t
{
	int id;
	int out;
};
int main(int argc, const char *argv[])
{
	struct people_t a[N];
	int i, k, say = 0 ,sum = 0;
	for (i = 0; i < N; i++) 
	{
		a[i].id=i+1;
		a[i].out = 0;
	}
	
	for (i = 0; ; i++) 
	{
		if(a[i%N].out == 0)
		{
			say++;
			if(say%M == 0)
			{
				say = 0;
				a[i%N].out = 1;
				printf("%2d  out\n",a[i%N].id);
			}
		}
		for (k = 0; k < N; k++) 
		{
			sum = sum + a[k].out;
		}
		if(sum == N-1)
			break;
		else
			sum = 0;
	}
	for (i = 0; i < N; i++) 
	{
		if(a[i].out == 0)
		{
			printf("The last is: %d\n",a[i].id);
			break;
		}
	}
	/*for (i = 0; i < N; i++) 
	{
		printf("%d %d\n",a[i].id,a[i].out);
	}*/
	return 0;
}
