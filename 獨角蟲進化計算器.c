// #include <bits/stdc++.h>
// using namespace std;
// int main() {
// 	int candy,weedle,evole;
// 	while(cin>>candy>>weedle) {
// 		while(candy+weedle>=13) {
// 			if(candy>=12) {
// 				candy-=11;
// 				evole+=1;
// 			}
// 			else {
// 				weedle--;
// 				candy++;
// 			}
// 		}
// 		cout<<evole<<endl;
// 	}
// }
# include <stdio.h>

int main(void)
{
    int candy, weedle, kakuna;
    scanf("%d %d", &candy, &weedle);
    while(candy + weedle > 12)
    {
        if(candy >= 12)
        {
            candy -= 12;
            kakuna ++;
            candy ++;
        }
        else
        {
            weedle --;
            
        }
    }
}