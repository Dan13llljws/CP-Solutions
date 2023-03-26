#include <iostream>
int n, a, b, c, ans;
int main(){
	scanf("%d%d%d%d", &n, &a, &b, &c);
	while(1){
		n--, a++, ans++;
		if (!(a % 35)) n += 30;
		if (!n) return 0 * printf("Martha plays %d times before going broke.\n", ans);
		n--, b++, ans++;
		if (!(b % 100)) n += 60;
		if (!n) return 0 * printf("Martha plays %d times before going broke.\n", ans);
		n--, c++, ans++;
		if (!(c % 10)) n += 9;
		if (!n) return 0 * printf("Martha plays %d times before going broke.\n", ans);
	}
}
