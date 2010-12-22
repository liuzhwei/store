// a game about Josephus.N people say number for 0 to M. the people who
// shoud say M will be killed,and the next one say 0 begin.
// what the programming done is show who be killed one by one, and who be last.

#include <stdio.h>
#define M 5  //who say the number was killed.
#define N 20 //number of all people.

struct people_t
{
	int id;  //everyone's number
	int out;  //status be killed or not
};
int main(int argc, const char *argv[])
{
	struct people_t a[N];
	int i, k, say = 0 ,sum = 0;
	for (i = 0; i < N; i++)  //initcial. 
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
				printf("%d\t  out\n",a[i%N].id);
			}
		}
		for (k = 0; k < N; k++) 
		{
			sum = sum + a[k].out;
		}
		if(sum == N-1)   //if only one live.
			break;
		else
			sum = 0;
	}
	for (i = 0; i < N; i++) 
	{
		if(a[i].out == 0)  //who is the last one.
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
