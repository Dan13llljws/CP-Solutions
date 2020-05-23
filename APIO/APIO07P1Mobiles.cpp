#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, base = 131, MM = 1e5 + 5;
int n, ans, mx, mn = INF, l[MM], r[MM];
void dfs(int src, int d){
	if (src == -1) mx = max(mx, d), mn = min(mn, d);
	else dfs(l[src], d + 1), dfs(r[src], d + 1);
}
int dfs2(int src, int d){
	if (src == -1) return d == mn ? 1 : 2;
	int x = dfs2(l[src], d + 1), y = dfs2(r[src], d + 1);
	if ((x == 1 && y == 2) ||(x == 1 && y == 3) || (x == 3 && y == 2)) ans++;
	if (x == 3 && y == 3){printf("-1"); exit(0);}
	return x | y;
}
int main(){
	n = re;
	for (int i = 1; i <= n; i++) l[i] = re, r[i] = re;
	dfs(1, 0);
	if (mx - mn > 1) return 0 * printf("-1");
	if (mx == mn) return 0 * printf("0");
	dfs2(1, 0);
	printf("%d", ans);
	return 0;
}
