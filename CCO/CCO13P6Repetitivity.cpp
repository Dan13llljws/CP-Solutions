#include <stdio.h>
#include <cstring>
char s[10005]; int n, mod, dp[10005];
int add(int a,int b){
	a += b;
	if (a > mod) a -= mod;
	return a;
}
int main(){
	gets(s + 1); scanf("%d", &mod); n = strlen(s + 1), dp[0] = 1;
	for (int i = 1; i <= n; i++){
		int tmp = 0;
		for (int j = 1; j < n; j++){
			if (s[i] == s[j]) tmp = dp[j - 1];
			dp[j] = add(dp[j], tmp);
		}
		dp[i] = add(dp[i - 1], dp[i - 1]);
	}
	printf("%d\n", dp[n]);
}
