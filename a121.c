# include <stdio.h>
# include <math.h>
int isprime(int);

int main(void)
{
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF)
    {
        int count = 0;
        for(int i = a; i <= b; i++)
        {
            if(isprime(i) && i != 1)
                count++;
        }
        printf("%d\n", count);
    }
}

int isprime(int n)
{
    if(n == 2)
        return 1;
    else if(n % 2 == 0)
        return 0;
    else
    {
        int r = (int)floor(sqrt(n)+0.5);
        for(int i = 3; i <= r; i++)
        {
            if(n % i == 0)
                return 0;
        }
        return 1;
    }
}