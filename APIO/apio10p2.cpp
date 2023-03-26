#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define ms(x, y) memset(x, y, sizeof x)
const int mod = 1e9 + 7, MM = 1e5 + 5;
struct edge{int v, w, nxt;}edges[2*MM]; // chinese adj list makes life sm easier
int n, m, tot, maxd, rt, ans, head[MM], best[MM], sec[MM], ch[MM][2];
void dfs(int src, int par){
	best[src] = sec[src] = 0, ch[src][0] = ch[src][1] = -1;
	for (int i = head[src]; i >= 0; i = edges[i].nxt){
		int v = edges[i].v, w = edges[i].w;
		if (v == par) continue;
		dfs(v, src);
		int d = best[v] + w;
		if (d > best[src]) sec[src] = best[src], best[src] = d, ch[src][1] = ch[src][0], ch[src][0] = i;
		else if (d > sec[src]) sec[src] = d, ch[src][1] = i;
	}
	if (best[src] + sec[src] > maxd) maxd = best[src] + sec[src], rt = src;
}
int main(){
	n = re, m = re; ms(head, -1);
	for (int i = 1; i < n; i++){
		int a = re, b = re;
		edges[tot] = {b, 1, head[a]}, head[a] = tot++;
		edges[tot] = {a, 1, head[b]}, head[b] = tot++;
	}
	dfs(1, 1); ans = 2 * (n - 1) - maxd + 1; 
	if (m == 1) return 0 * printf("%d", ans);
	for (int k = 0; k <= 1; k++)
		for (int i = ch[rt][k]; i != -1; i = ch[edges[i].v][0])
			edges[i].w = edges[i ^ 1].w = -1;
	maxd = 0; dfs(1, 1); ans -= maxd - 1;
	printf("%d\n", ans); 
}
