#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7, MM = 2e3 + 5;
int n, m, t, h[MM], st[MM]; char s[MM]; ll ans;
ll f(int x){return 1LL * x * (x + 1) / 2;}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%s", s + 1); t = 0;
		for (int j = 1; j <= m; j++)
			if (s[j] == '.') h[j]++;
			else h[j] = 0;
		for (int j = 1; j <= m + 1; j++){
			while(t && h[j] < h[st[t]]){
				int tp = st[t--], r = j - tp, l = tp - st[t];
				ans += f(h[tp]) * (l * f(r) + r * f(l) - l * r);
			}
			st[++t] = j;
		}
	}
	printf("%lld", ans);
}

