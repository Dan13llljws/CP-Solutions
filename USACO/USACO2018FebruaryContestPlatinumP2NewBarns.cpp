#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, base = 131, MM = 1e5 + 5;
int Q, n, rt[MM], l[MM], r[MM], dep[MM], dia[MM], anc[MM][20];
int lca(int u, int v){
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 18; i >= 0; i--)
		if (dep[u] - (1 << i) >= dep[v]) u = anc[u][i];
	if (u == v) return u;
	for (int i = 18; i >= 0; i--)
		if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
	return anc[u][0];
}
int dist(int u, int v){return dep[u] + dep[v] - 2 * dep[lca(u, v)];}
int main(){
	Q = re; 
	while(Q--){
		char cmd = getchar(); int u = re;
		if (cmd == 'B'){
			n++;
			if (u == -1) rt[n] = l[n] = r[n] = n;
			else {
				rt[n] = rt[u], dep[n] = dep[u] + 1, anc[n][0] = u;
				for (int i = 1; i <= 18; i++) anc[n][i] = anc[anc[n][i - 1]][i - 1];
				int dl = dist(l[rt[u]], n), dr = dist(r[rt[u]], n);
				if (dl > dia[rt[u]]) dia[rt[u]] = dl, r[rt[u]] = n;
				if (dr > dia[rt[u]]) dia[rt[u]] = dr, l[rt[u]] = n;
			}
		} else printf("%d\n", max(dist(u, l[rt[u]]), dist(u, r[rt[u]])));
	}
}

