#include <stdio.h>

void dtob(void)
{
	int k, i, a[32];
	printf("Please input a number:");
	scanf("%d",&k);
	for (i = 0; i < 32; i++) {
		a[31 - i] = k & 0x01;
		k>>=1;
	}
	for (i = 0; i < 32; i++) 
		printf("%d",a[i]);
	printf("\n\n");
}

void mul(void)
{
	unsigned int aa, bb, t = 1, i = 0, sum = 0, h;
	printf("Please input x y:");
	scanf("%d %d",&aa,&bb);
	for(i = 0; i < 32; i++) {
		if(bb & t) {
			h = aa<<i;
			sum = sum + h;
		}
		bb = bb>>1;
	}
	printf("%d*%d=%d\n\n",aa,bb,sum);
}

void exchange(void)
{	
	char ss[128];
	int i = -1;

	printf("Please input a string:");
	getchar();
	//scanf("%s",ss);
	fgets(ss,128,stdin);
	while(ss[++i]){
		if('a' <= ss[i] && ss[i] <= 'z')
			ss[i]-= ('a' - 'A');
		else if('A' <= ss[i] && ss[i] <= 'Z')
			ss[i]+= ('a' - 'A');
	}
	printf("%s\n",ss);
}

void encryption(void)
{	
	char pre,aft;

	printf("Please input a char:");
	getchar();
	scanf("%c",&pre);
	aft = pre^'A';
	if(aft == ' ' || aft == '\0' || aft == '\n' || aft == '\t')
		printf("the character is invisible\n");
	else 
		printf("After encrytion:%c\n\n",aft);
}

int main(int argc, const char *argv[])
{
	int t = 0;
kk:
	printf("Please select the option:\n1.Decimal to binary\n2.x*y\n3.low or up exchange\n4.Encryption\n5.Exit\nPlease choose[1-5]:");
	scanf("%d",&t);
	switch(t) {
		case 1:
			dtob();
			goto kk;
			break;
		case 2:
			mul();
			goto kk;
			break;
		case 3:
			exchange();
			goto kk;
			break;
		case 4:
			encryption();
			goto kk;
			break;
		case 5:
			return 0;
			break;
	}
	return 0;
}
