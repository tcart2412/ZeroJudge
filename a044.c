# include <stdio.h>

int main(void)
{
	int n;
	while(scanf("%d", &n) != EOF)
		printf("%d\n", (power(n, 3) + (5 * n) + 6) / 6); 
}

int power(int x, int n)
{
	if(n == 0)
		return 1;
	else
		return x * power(x, n - 1);
}
