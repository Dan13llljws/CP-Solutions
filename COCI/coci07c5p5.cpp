#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 3e5 + 5, MN = 1e5 + 5;
struct p{int x, y, f;}s[MM];
int n, k, idx, dp[MM], x[MN], y[MN], px[MM], py[MM], pre[MM]; pii st, ed; vector<int> v;
bool cmp(p a, p b){return a.x + a.y < b.x + b.y;}
int main(){
	n = re, k = re;
	for (int i = 0; i < n; i++) s[i] = {re, re, re};
	st = {s[0].x, s[0].y}, ed = {s[n - 1].x, s[n - 1].y}; sort(s, s + n, cmp);
	for (int i = 0; i < n; i++)
		if (s[i].x == st.first && s[i].y == st.second){idx = i; break;}
	x[s[idx].x] = y[s[idx].y] = dp[idx] = s[idx].f;
	for (int i = idx + 1; i < n; i++){
		if (x[s[i].x] >= k && x[s[i].x] - k + s[i].f > dp[i]) dp[i] = x[s[i].x] - k + s[i].f, pre[i] = px[s[i].x];
		if (y[s[i].y] >= k && y[s[i].y] - k + s[i].f > dp[i]) dp[i] = y[s[i].y] - k + s[i].f, pre[i] = py[s[i].y];
		if (dp[i] > x[s[i].x]) x[s[i].x] = dp[i], px[s[i].x] = i;
		if (dp[i] > y[s[i].y]) y[s[i].y] = dp[i], py[s[i].y] = i;
	}
	for (int i = 0; i < n; i++)
		if (s[i].x == ed.first && s[i].y == ed.second){idx = i; break;}
	for (int i = idx; i; i = pre[i])
		v.push_back(i);
	printf("%d\n%d\n%d %d\n", dp[idx], (int)(v.size()) + 1, st.first, st.second);
	for (int i = v.size() - 1; i >= 0; i--) printf("%d %d\n", s[v[i]].x, s[v[i]].y);
}

