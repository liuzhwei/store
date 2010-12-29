/****
 *  by charactar....
 *  fgetc() and fputc() functions
 */
#include <stdio.h>

int main(int argc, const char *argv[])
{
	FILE * aa, * bb;
	int c;
	if(argc != 3) {
		printf("Putin errer.......\n");
		return 1;
	}
	aa = fopen(argv[1],"r");
	bb = fopen(argv[2],"a");
	while(1) {
		c = fgetc(aa);
	//	if(c != EOF)
		if(!feof(aa))
			fputc(c,bb);
		else break;
	}
	fclose(aa);
	fclose(bb);
	return 0;
}
/*
*************************************/

/*
 *  by string......
 *  fgets() and fputs() functions

#include <stdio.h>

int main(int argc, const char *argv[])
{
	FILE * aa, * bb;
	int c;
	char st[5];
	if(argc != 3) {
		printf("Putin errer.......\n");
		return 1;
	}
	aa = fopen(argv[1],"r");
	bb = fopen(argv[2],"a");
	while(1) {
		fgets(st,5,aa);
		if(feof(aa))
			break;
		fputs(st,bb);
	}
	fclose(aa);
	fclose(bb);
	return 0;
}
*****************************************/

/*
 * fread() and fwrite() functions
#include <stdio.h>

int main(int argc, const char *argv[])
{
	FILE * str1, * str2;
	int a = 0, aa = 0, b = 0, bb = 0;
	char ss[1024];
kk:
	str1 = fopen(argv[1],"r");
	str2 = fopen(argv[2],"w");
	while(1) {
		a = fread(ss,1,1,str1);
		aa+= a;
		if(!feof(str1)) {
			b = fwrite(ss,1,1,str2);
			bb+= b;
		}else break;
	}
	printf("aa:%d\n",aa);
	printf("bb:%d\n",bb);
	if(aa != bb) {
		aa = 0;
		bb = 0;
		goto kk;
	}

	return 0;
}
******************************************/
