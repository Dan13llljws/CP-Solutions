#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, n, cnt, mn = 1e9;
int main(){
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &n);
	for (int i = 0; i <= n / a; i++)
		for (int j = 0; j <= n / b; j++)
			for (int k = 0; k <= n / c; k++)
				for (int l = 0; l <= n / d; l++)
					if (i * a + j * b + k * c + l * d == n){
						printf("# of PINK is %d # of GREEN is %d # of RED is %d # of ORANGE is %d\n", i, j, k, l);
						mn = min(mn, i + j + k + l), cnt++;
					}
	printf("Total combinations is %d.\nMinimum number of tickets to print is %d.", cnt, mn);
}
