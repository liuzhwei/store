// programing analys(jie_xi) shell commands.
// putin a command with argumment or not. display what is command;
// what is argumment; what is in_file and what is out_file.
#include <stdio.h>
#define N 50  //lenth of charactor arry.

char cc[N];
char *p;
typedef struct {
	char *a[6];
	char *in;
	char *out;
} command_t;

/** 
* @brief get a string for keybord and stored it in cc[].
*/
void get_string(void)
{
	int b;
	for (b = 0; b < N; b++) 
	{
		cc[b] = 'b';
	}
	p = fgets(cc,N,stdin);
}

/** 
* @brief : analys the string which we putin. divese command and arguments.
* 
* @param cmd: address string which we get in get_string program. 
* 
* @return : return a struct variable. It contain address of command we putin
*         ,argument,in_file and out_file.
*/
command_t analys(char * cmd)
{
	command_t c;
	int i = 0, j = 0;

	for (i = 5; i >= 0; i--)
		c.a[i] = NULL;
	c.in = NULL;
	c.out = NULL;

	c.a[0] = cmd;
	while (cmd[++i]) {
		if (cmd[i] == ' ') {
			while (cmd[++i] == ' ')
				;
			if (cmd[i] != '<' && cmd[i] != '>') {
				cmd[i - 1] = '\0';
				c.a[++j] = cmd + i;
			}
		}
		if (cmd[i] == '<') {
			cmd[i] = '\0';
			while (cmd[++i] == ' ')
				;
			c.in = cmd + i;
		}
		if (cmd[i] == '>') {
			cmd[i] = '\0';
			while (cmd[++i] == ' ')
				;
			c.out = cmd + i;
		}
	}
	return c;
}

/** 
* @brief :display all us asked for.
* 
* @param t : recieve the cc[].
*/
void show(char *t)
{
	command_t cmdt = analys(t);
	int k = 0;

	printf("\n");
	printf("Command: %s\n",cmdt.a[0]);
	for(k = 1; k < 6; k++)
		if (cmdt.a[k] != NULL)
			printf("Argument[%d]: %s\n",k,cmdt.a[k]);
	printf("In file: %s\n",cmdt.in);
	printf("Out file: %s",cmdt.out);
	return;
}

int main(int argc, const char *argv[])
{
	while(1) {
		get_string();
		show(cc);
	}                          // ended the programing by Ctrl+c in bash.

	return 0;
}
