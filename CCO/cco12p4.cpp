#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define Push if (dist[nx][ny] > dist[x][y] + 1) dist[nx][ny] = dist[x][y] + 1, q.push({nx, ny})
const int mod = 1e9 + 7, MM = 1e5 + 5;
int n, rs, cs, rf, cf, a[MM], dist[MM][80]; queue<pii> q;
int main(){
	n = re; memset(dist, inf, sizeof dist);
	for (int i = 1; i <= n; i++) a[i] = re;
	rs = re, cs = re, rf = re, cf = re;
	dist[rs][cs] = 0; q.push({rs, cs});
	while(!q.empty()){
		int x = q.front().first, y = q.front().second, nx, ny; q.pop();
		if (x == rf && y == cf) return 0 * printf("%d\n", dist[x][y]);
		if (x != 1){nx = x - 1, ny = min(y, a[nx]);Push;}
		if (x != n){nx = x + 1, ny = min(y, a[nx]);Push;}
		if (y != 1){nx = x, ny = y - 1;Push;} 
		else if (x != 1){nx = x - 1, ny = a[nx];Push;}
		if (y != a[x]){nx = x, ny = y + 1;Push;} 
		else if (x != n){nx = x + 1, ny = 1;Push;}
	}
}
