#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e5 + 15;
int S, T, n, m, t, rt, bcc, acnt, top, flask, msz, mnc, spec, d[MM], p[MM], st[MM], in[MM], low[MM]; vector<int> adj[MM]; queue<int> q;
// flask: 3 ways of going up, go down, parent, back edge
// moon: cycle
// sun: bcc w 4+ nodes
// talon: in deg >= 3
// fox: is a fucking cancer
int dfs0(int src, int par){
	in[src] = 1;
	for (int v : adj[src]){
		if (v == par) continue;
		if (in[v] || dfs0(v, src)) return 1;
	} return 0;
}	
void dfs1(int src, int par){
	in[src] = low[src] = ++t, st[++top] = src; int bcnt = 0, ch = 0, art = 0, ech = 0;
	for (int v : adj[src]){
		if (in[v]){
			low[src] = min(low[src], in[v]); 
			if (in[v] < in[src]) bcnt++;
			if (in[v] < in[src] && v != par) ech |= 2;
		}
		else {
			dfs1(v, src); low[src] = min(low[src], low[v]), ch++;
			if (low[v] < in[src]) bcnt++, ech |= 2;
			if (low[v] == in[src]){
				bcc++, ech |= 1; int sz = 1;
				for (int x = 0; x != v;) x = st[top--], sz++;
				msz = max(msz, sz); art |= par != rt;
			}
		}
	} acnt += art;
	if (par == rt && ch > 1) acnt++;
	if (ech == 3) spec = 1;
	if (bcnt > 2) flask = 1;
}
void dfs2(int src, int par){
	d[src] = d[par] + 1;
	for (int v : adj[src])
		if (!d[v]) dfs2(v, src);
		else if (abs(d[v] - d[src]) > 1) mnc = min(mnc, abs(d[v] - d[src]) + 1);
}
int main(){
	S = re, T = re;
	while(T--){
		n = re, m = re, bcc = top = t = msz = flask = acnt = spec = 0, rt = 1, mnc = 1e9;
		for (int i = 1; i <= n; i++) adj[i].clear(), in[i] = low[i] = d[i] = 0;
		for (int i = 0; i < m; i++){
			int a = re, b = re;
			adj[a].push_back(b), adj[b].push_back(a);
		}
		if (S == 1) dfs1(1, 1), puts(flask ? "YES" : "NO"); 
		else if (S == 2) puts(dfs0(1, 1) ? "YES" : "NO");
		else if (S == 3) dfs1(1, 1), puts(msz> 3 ? "YES" : "NO");
		else if (S == 4){
			bool w = 0;
			for (int i = 1; i <= n; i++)
				if ((int)adj[i].size() > 2){w = 1; break;}
			puts(w ? "YES" : "NO");
		} else {
			for (int i = 1; i <= n; i++) if ((int)adj[i].size() == 1) rt = i;
			dfs1(rt, rt);
			if (bcc > 2){
				if (flask) puts("YES");
				else if ((int)adj[rt].size() == 1) puts(acnt > 1 ? "YES" : "NO");
				else puts(spec ? "YES" : "NO");
			}
			else if (bcc == 2) puts(flask ? "YES" : "NO");
			else {
				for (int i = 1; i <= n; i++)
					memset(d, 0, sizeof d), dfs2(i, i);
				puts(n > mnc + 1 ? "YES" : "NO");
			}
		}
	}
}

