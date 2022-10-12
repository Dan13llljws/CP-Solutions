#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 3005;
int n, m, k, ans, s[MM], d[MM]; ll a, b, c, t; priority_queue<pii> q;
int main(){
	n = re, m = re, k = re - m, a = re, b = re, c = re, t = re;
	for (int i = 0; i < m; i++) s[i] = re;
	for (int i = 0; i < m - 1; i++){
		if ((s[i] - 1) * b > t) continue;
		d[i] = min(1LL * s[i + 1] - 1, s[i] + (t - (s[i] - 1) * b) / a);
		ans += d[i] - s[i] + 1;
		if (t >= (s[i] - 1) * b + (d[i] - s[i] + 1) * c)
			q.push({min(1LL * s[i + 1] - 1, d[i] + (t - (s[i] - 1) * b - (d[i] - s[i] + 1) * c) / a + 1) - d[i], i});
	}
	if ((n - 1) * b <= t) ans++;
	while(k-- && q.size()){
		pii p = q.top(); q.pop();
		ans += p.first;
		d[p.second] += p.first;
		if (t >= (s[p.second] - 1) * b + (d[p.second] - s[p.second] + 1) * c)
			q.push({min(1LL * s[p.second + 1] - 1, d[p.second] + (t - (s[p.second] - 1) * b - (d[p.second] - s[p.second] + 1) * c) / a + 1) - d[p.second], p.second});
	}
	printf("%d\n", ans - 1);
}
