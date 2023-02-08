# include <stdio.h>

int main(void)
{
    int row, col;
    while(scanf("%d %d", &row, &col) != EOF)
    {
        int arr[row][col];
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                int z;
                scanf("%d", &z);
                arr[i][j] = z;
            }
        }
        for(int i = 0; i < col; i++)
        {
            for(int j = 0; j < row; j++)
                printf("%d ", arr[j][i]);
            printf("%c", '\n');
        }
    }
}