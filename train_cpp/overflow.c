#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_auth(char *pass)
{
	int auth_flag = 0;
	char pass_buffer[16];

	strcpy(pass_buffer, pass);
	if (strcmp(pass_buffer, "brillig") == 0)
		auth_flag = 1;
	if (strcmp(pass_buffer, "outgrabe") == 0)
		auth_flag = 1;
	return auth_flag;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Usage: %s <password>\n", argv[0]);
		exit(0);
	}
	if (check_auth(argv[1]))
	{
		printf("ACCESS GRANTED\n");
	}
	else
	{
		printf("ACCESS DENIED\n");
	}
}