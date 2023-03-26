#include <bits/stdc++.h>
int n;
int main(){
	while(scanf("%d", &n), n){
		for (int i = sqrt(n); i; i--)
			if (n % i == 0){
				printf("Minimum perimeter is %d with dimensions %d x %d\n", 2 * (i + n / i), i, n / i);
				break;
			}
	}
}
