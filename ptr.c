#include <stdio.h>
 
int main ( void ){
	int n;
	scanf("%d",&n);
	int a[n],b[n];
	int i,j,temp;
	for(i = 0; i < n; i++){
		scanf("%d %d",&a[i],&b[i]);
	}
	int min = 1000000;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if( i == j ){
				temp = a[i] + b[j];
			} else if(a[i] > b[j]) {
				temp = a[i];
			} else {
				temp = b[j];
			}
			if( temp < min ) min = temp;
		}
	}
	printf("%d",min);
	return 0;
}
