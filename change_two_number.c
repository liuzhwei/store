// change a and b
// needn't c
#include <stdio.h>

int main(int argc, const char *argv[])
{
	
	char a = 5, b = 7;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("%d\n",a);
	printf("%d\n",b);
	return 0;
}
