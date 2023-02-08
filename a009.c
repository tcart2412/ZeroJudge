# include <stdio.h>
# include <string.h>

int main(void)
{
	char ip[1000];
	gets(ip);
	for(int i = 0; i < strlen(ip); i++)
		printf("%c", ip[i] - 7);
}
