#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e5 + 5;
int n, dsu[MM], t[MM]; pii p[MM]; ll ans; vector<int> adj[MM];
int Find(int x){return dsu[x] == x ? x : dsu[x] = Find(dsu[x]);}
void unite(int x, int y){x = Find(x), y = Find(y), t[y] = max(t[y], t[x]), dsu[x] = y;}
int main(){
	n = re;
	for (int i = 1; i <= n; i++) t[i] = re, dsu[i] = i;
	for (int i = 1; i < n; i++) p[i] = {re, re};
	sort(p + 1, p + n, [](auto a, auto b){return max(t[a.first], t[a.second]) < max(t[b.first], t[b.second]);});
	for (int i = 1; i < n; i++)
		ans += t[Find(p[i].first)] + t[Find(p[i].second)], unite(p[i].first, p[i].second);
	printf("%lld\n", ans);
}
