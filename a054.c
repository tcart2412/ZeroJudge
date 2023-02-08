# include <stdio.h>
int myatoi(char s[]);
int power(int, int);

int main(void)
{
	char ltr[26];
	for(int i = 0; i < 26; i++)
		ltr[i] = 65 + i;
	int num[] = {10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20,
				21, 22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33};
	char input[100];
	while(scanf("%s", input) != EOF)
	{
		int check, x, sum = 0;
		if(input[8] - 48 != 0)
			check = input[8] - 48;
		else
			check = 10;
		for(int i = 0; i < 8; i++)
			sum += (input[i] - 48) * (8 - i);
		for(int i = 0; i < 26; i++)
		{
			x = (num[i] / 10) + ((num[i] % 10) * 9) + sum;
			if((10 - (x % 10)) == check)
				printf("%c", ltr[i]);
		}
		printf("%c", '\n');
		printf("%d", myatoi("12345"));
	}
	
}

int myatoi(char s[])
{
	int sum = 0;
	int flag = 1;
	int i = 0;
	int len = strlen(s);
	if(s[0] == '-')
	{
		flag = -1;
		i ++;
	}
	for(i; i < len; i++)
		sum += (s[i] - 48) * power(10, (len - 1 - i));
	return flag * sum;
}

int power(int x, int n)
{
	if(n == 0)
		return 1;
	else
		return power(x, n - 1) * x;
}
