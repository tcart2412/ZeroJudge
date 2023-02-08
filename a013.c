# include <stdio.h>
# include <string.h>
int romanToInt(char str[]);
int getValue(char);
void intToRoman(int);
int abs(int);

int main(void)
{
	char str1[100];
	char str2[100];
	int a, b;
	while(scanf("%s", str1))
	{
		if(str1[0] == '#')
			break;
		scanf("%s", str2);
		a = romanToInt(str1);
		b = romanToInt(str2);
		if(abs(a - b) == 0)
			printf("ZERO\n");
		else
			intToRoman(abs(a - b));
	}
}
int romanToInt(char str[])
{
	int z, sum = 0;
	for(int i = 0; i < strlen(str); i++)
	{
		z = getValue(str[i]);
		if(i == strlen(str) - 1)
		{
			sum += z;
			break;
		}
		else if(z < getValue(str[i + 1]))
			sum -= z;
		else
			sum += z;
	} 
	return sum;
}

int getValue(char ch)
{
	char str[] = "MDCLXVI";
	int num[] = {1000, 500, 100, 50, 10, 5, 1};
	for(int i = 0; i < strlen(str); i++)
	{
		if(ch == str[i])
			return num[i];
	}
}
void intToRoman(int x)
{
	char str[][3] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
	int num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
	int n = 12;
	int z;
	while(n > 0)
	{
		int d;		
		if(num[n] <= x)
		{
			z = x % num[n];
			d = x / num[n];
			if(d > 1)
			{
				for(int i = 0; i < d; i++)
					printf("%s", str[n]);
			}
			else
				printf("%s", str[n]);
			x = z;
		}
		n --;
	}
	for(int i = 0; i < x; i++)
		printf("%c", 'I');
	printf("%c", '\n');
}

int abs(int x)
{
	if(x < 0)
		return -x;
	else
		return x;
} 