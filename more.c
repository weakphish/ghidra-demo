#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *doSomething(char *buff, int len)
{
	for (int i = 0; i < len; i++)
	{
		buff[i] = toupper(buff[i]);
	}

	return buff;
}

int main(void)
{
	char buff[] = "this";
	printf("Hm... I wonder what %s is?\n", buff);
	char *res = doSomething(buff, strlen(buff));
	printf("Oh... it's %s...\n", res);
}