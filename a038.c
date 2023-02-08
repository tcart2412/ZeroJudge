# include <stdio.h>
# include <string.h>
int main(void)
{
    char arr[1000];
    char temp;
    while(scanf("%s", arr) != EOF)
    {
        for(int i = 1; i <= strlen(arr); i++)
        {
            for(int j = 0; j < strlen(arr) - i; j++)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        int c, count = 0;
        for(int i = 0; i < strlen(arr); i++)
        {
            if(arr[i] != '0')
            {
                c = i;
                break;
            }
            else
                count ++;
        }
        if(count == strlen(arr))
            printf("%d", 0);
        else
        {
            for(int i = c; i <= strlen(arr); i++)
                printf("%c", arr[i]);
        }
        printf("%c", '\n');
    }
}