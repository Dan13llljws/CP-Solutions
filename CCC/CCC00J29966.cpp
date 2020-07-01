#include <iostream>
int a, b, ans, dig[10];
bool check(int x){
	int sz = 0;
	while(x) dig[sz++] = x % 10, x /= 10;
	for (int i = 0; i < sz; i++){
		if (dig[i] != 1 && dig[i] != 0 && dig[i] != 8 && dig[i] != 6 && dig[i] != 9) return 0;
		if (dig[i] == 1 && dig[sz-i-1] != 1) return 0;
		if (dig[i] == 0 && dig[sz-i-1] != 0) return 0;
		if (dig[i] == 8 && dig[sz-i-1] != 8) return 0;
		if (dig[i] == 6 && dig[sz-i-1] != 9) return 0;
		if (dig[i] == 9 && dig[sz-i-1] != 6) return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d", &a, &b);
	for (int i = a; i <= b; i++) ans += check(i);
	printf("%d", ans);
}
