# include <stdio.h>

int main(void)
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		if(n >= 0 && n <= 10)
			printf("%d\n", 6 * n);
		else if(n <= 20)
			printf("%d\n", 60 + (2 * (n - 10)));
		else if(n < 40)
			printf("%d\n", 80 + (n - 20));
		else
			printf("%d\n", 100);
	}
}
