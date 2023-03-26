#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
int n, q, l[26][MM], r[26][MM]; char s[MM];
int main(){
	scanf("%d%d %s", &n, &q, s + 1);
	for (int i = 0; i < 26; i++){
		bool f = 0; int cur = 0;
		for (int j = 1; j <= n; j++){
			if (s[j] < 'A' + i && f) f = 0;
			if (s[j] == 'A' + i && !f) f = 1, cur++;
			l[i][j] = cur;
		}
		f = 0, cur = 0;
		for (int j = n; j > 0; j--){
			if (s[j] < 'A' + i && f) f = 0;
			if (s[j] == 'A' + i && !f) f = 1, cur++;
			r[i][j] = cur;
		}
	}
	while(q--){
		int a, b; scanf("%d%d", &a, &b);
		int ans = 0;
		for (int i = 0; i < 26; i++) ans += l[i][a - 1] + r[i][b + 1];
		printf("%d\n", ans);
	}
}
		
