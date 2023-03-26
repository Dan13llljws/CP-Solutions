#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, base = 131, MM = 2e5 + 5;
int n, a[MM], b[MM], bit[MM]; ll ans;
vector<int> f[MM]; priority_queue<int> q;
void update(int p){for (; p <= n; p += p & -p) bit[p]++;}
int query(int p){
	int ret = 0;
	for (; p; p -= p & -p) ret += bit[p];
	return ret;
}
int main(){
	n = re;
	for (int i = 1; i <= n; i++) f[re].push_back(i);
	for (int i = n; i; i--){
		for (int x : f[i]) q.push(x);
		if (q.empty()) return 0 * printf("-1\n");
		int r = q.top(); q.pop();
		ans += i - r + query(r);
		update(r);
	}
	printf("%lld", ans);
}

