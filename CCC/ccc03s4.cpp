#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, base = 131;
typedef unsigned long long ull;
const int MM = 5e3 + 5;
int t, n; ull h[MM], p[MM]; char str[MM];
unordered_set<ull> vis;
ull get(int l, int r){return h[r] - h[l - 1] * p[r - l + 1];}
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", str + 1);
		n = strlen(str + 1); p[0] = 1;
		for (int i = 1; i <= n; i++){
			h[i] = h[i - 1] * base + str[i] - 'a';
			p[i] = p[i - 1] * base;
		}
		int ans = 1;
		for (int len = 1; len <= n; len++){
			for (int i = 1; i <= n - len + 1; i++) vis.insert(get(i, i + len - 1));
			ans += (int)vis.size(); vis.clear();
		}
		printf("%d\n", ans);
	}
	return 0;
}
