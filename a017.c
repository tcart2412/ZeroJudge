# include <stdio.h>
# include <string.h>
# include <stdlib.h>
int postfix(char str[]);
int priority(char);
int evalPf(char postfix[]);
int cal(int, char, int);
int myatoi(char s[]);
int power(int, int);
char demo[80] = {'\0'};

int main(void)
{
	char str[80][5] = {'\0'};
	char input[80] = {'\0'};
	while(gets(input))
	{
		int i = 0, n = 0, k = 0;
		while(i < strlen(input))
		{
			k = 0;
			while(input[i] != ' ')
			{
				str[n][k] = input[i];
				i ++;
				k ++;
			}
			n ++; 
			i ++;
		}
		for(int i = 0; i < n; i++)
			printf("%s\n", str[i]);
//		postfix(str);
//		printf("後序表達式:%s\n", demo);
//		evalPf(demo);
//		printf("%c", '\n');
	}
}

int postfix(char str[])
{
	int n = 0, top = 0;
	char stack[80] = {'\0'};
	char op;
	int k = 0;
	while(1)
	{
		op = str[n];
		switch (op)
		{
			case '(':
				if(top < 80)
				{
					top ++;
					stack[top] = op;
				}
				break;
			case ')':
				while(stack[top] != '(')
				{
//					printf("%c", stack[top]);
					demo[k] = stack[top];
					k ++;
					top --;
				}
				top --;
				break;
			case '+': case '-': case '*': case '/': case '%':
				while(priority(stack[top]) >= priority(op))
				{ 
//					printf("%c", stack[top]);
					demo[k] = stack[top];
					k ++;
					top --;
				}
				if(top < 80)
				{
					top ++;
					stack[top] = op;
				}
				break;
			case '\0':
				while(top > 0)
				{
//					printf("%c", stack[top]);
					demo[k] = stack[top];
					k ++;
					top --;
				}
				return 0;
			default:
//				printf("%c", op);
				demo[k] = op;
				k ++;
				break;
		}
		n ++;
	}
}

int priority(char ch)
{
	switch (ch)
	{
		case '+': case '-':
			return 1;
		case '*': case '/':
			return 2;
		default:
			return 0;
	}
}

int evalPf(char postfix[])
{
	int n = 0, top = 0;
	int stack[80] = {0};
	char token;
	while(1)
	{
		token = postfix[n];
		switch (token)
		{
			case '\0':
				printf("%d", stack[top]);
				return 0;
			case '+': case '-': case '*': case '/': case '%':
				stack[top - 1] = cal(stack[top - 1], token, stack[top]);
				top --;
				break;
			default:
				if(top < 80)
				{
					top ++;
					stack[top] = token - 48;
				}
				break;
		}
		n ++;
	}
}

int cal(int p1, char op, int p2)
{
	switch (op)
	{
		case '+':
			return p1 + p2;
		case '-':
			return p1 - p2;
		case '*':
			return p1 * p2;
		case '/':
			return p1 / p2;
		case '%':
			return p1 % p2;
	}
}

int myatoi(char s[])
{
	int sum = 0;
	int len = strlen(s);
	for(int i = 0; i < len; i++)
		sum += s[i] * power(10, (len - 1) - i);
	return sum;
}

int power(int x, int n)
{
	if(n == 0)
		return 1;
	else
		return power(x, n - 1) * x;
}

			
