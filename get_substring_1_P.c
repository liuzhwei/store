//Without struct and with pointer,we mast change the parent string for get the 
//longset substring. Only we change a word to '\0',to pointing substring ended.


#include <stdio.h>
/** 
* @brief :get longest substring which maked by same word from parent string.
* 
* @param str:the parent string.
* 
* @return : return address of the longest substring.
*/
char * get_substr(char * str)
{
	int len = 0, i = 0, k = 0, sum = 0;
	char * sub_add = str;

	while(str[i] != '\0')
	{
		if(str[i+1] == str[i])
		{
			k++;
			sum++;
		}
		else 
		{
			if(k+1 > len)
			{
				len = k+1;
				sub_add = sub_add + sum + 1;
				sum = 0;
			}else
				sum++;
			k = 0;
		}
		i++;
	}
	sub_add[0] = '\0';  //pointing the end of substring.
	return sub_add - len;
}
int main(int argc, const char *argv[])
{
	char a[] = "aabbbccccccccffgklmmmn";	
	char c[] = "aaccccfffddddddcdf";
	char d[] = "";

	printf("%s\n",get_substr(a));
	printf("%s\n",get_substr(c));
	printf("%s\n",get_substr(d));
	return 0;
}
