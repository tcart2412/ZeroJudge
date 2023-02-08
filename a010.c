#include <stdio.h>
int isprime(int);

int main(void)
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        if(isprime(n))
            printf("%d", n);
        else
        {
            int z = n;
            int p = 0;
            for(int i = 2; i <= z; i++)
            {
                int count = 0;
                if(n % i == 0 && isprime(i))
                {
                    p ++;
                    while(n % i == 0)
                    {
                        n /= i;
                        count ++;
                    }
                    if(count > 1)
                    {
                        if(p == 1)
                            printf("%d^%d", i, count);
                        else
                            printf(" * %d^%d", i, count);
                    }
                        
                    if(count == 1)
                    {
                        if(p == 1)
                            printf("%d", i);
                        else
                            printf(" * %d", i);
                    }
                }
            }
        }
        printf("%c", '\n');
    }  
}

int isprime(int n)
{
    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0)
            count ++;
    }
    if(count == 2)
        return 1;
    else
        return 0;
}