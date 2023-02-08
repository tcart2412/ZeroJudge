#include <stdio.h>
#include <string.h>
int abs(int);

int main(void)
{
    int ch;
    char str[8];
    int i;
    while (scanf("%s", str) != EOF)
    {
        for (i = 0; i < 6; i++)
        {
            ch = abs(str[i] - str[i + 1]);
            printf("%d", ch);
        }
        printf("%c", '\n');
    }
}
int abs(int n)
{
    if (n < 0)
        return -n;
    else
        return n;
}