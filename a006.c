# include <stdio.h>
# include <math.h>
int main(void)
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int z = (b * b) - (4 * a * c);
	int r1 = (-b + sqrt(z)) / (2 * a);
	int r2 = (-b - sqrt(z)) / (2 * a); 
	if(z > 0)
		printf("Two different roots x1=%d , x2=%d\n", r1, r2);
	else if(z == 0)
		printf("Two same roots x=%d\n", -b / (2 * a));
	else
		printf("No real root\n"); 
}