//In this programming,we can get the longest substring which form by a same
// word. Using strcte needn't change the parent string.
#include <stdio.h>

typedef struct           //define type of sub_str_t. It is a struct form.
{
	const char * sub_addr;
	int len;
} sub_str_t;

/** 
* @brief :get longest substring for the parent string.
* 
* @param a : parent string.
* 
* @return : return a struct form. what infermation we can get from it is
*    address and length of the longest substring.
*/ 
sub_str_t get_sub(const char * a)
{
	sub_str_t f;
	f.sub_addr = a;
	f.len = 0;
	int i = 0,k = 0,sum = 0;

	while(a[i] != '\0')
	{
		if(a[i] == a[i+1])
		{
			k++;
			sum++;
		}
		else
		{
			if(f.len < k)
			{
				f.len = k + 1;
				f.sub_addr = f.sub_addr + sum + 1;
				sum = 0;
			}else
				sum++;
			k = 0;
		}
		i++;
	}
	f.sub_addr = f.sub_addr - f.len;

	return f;
}
int main(int argc, const char *argv[])
{
	char kk[] = "wwkkkkooppppppwerttt";
	int i;
	sub_str_t l;

	l = get_sub(kk);
	for (i = 0; i < l.len; i++) 
	{
		printf("%c",l.sub_addr[i]);
	}
	printf("\n");
	return 0;
}
