
//Variable argument function...
/*#include <stdio.h>

void myprint(char * format,...)
{
	char *p = (char *)&format;
	p+=4;
	printf("%s ",(char *)*(int *)p);
	p+=4;
	printf("%s ",(char *)*(int *)p);
	p+=4;
	printf("%s\n",(char *)*(int *)p);
}

int main(int argc, const char *argv[])
{
	myprint("","how","are","you");
	return 0;
}*/
#include <stdio.h>
#include <stdarg.h>

int sum(int format,...)
{
	int p, t,sum1 = 0;
	va_list ap;
	va_start(ap,format);
	while(format--) {
		t = va_arg(ap,int);
		sum1 = sum1 + t;
	}
	return sum1;
}

int main(int argc, const char *argv[])
{
	int t;
	t = sum(3,1,2,3);
	printf("%d\n",t);
	t = sum(5,1,1,1,1,1);
	printf("%d\n",5);
	return 0;
}
