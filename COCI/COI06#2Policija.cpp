#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e5 + 5;
struct edge{int v, nxt;} edges[10*MM];
int N, E, Q, t, tot, dep[MM], head[MM], in[MM], out[MM], low[MM], anc[MM][20];
void dfs(int src, int par){
	in[src] = low[src] = ++t, dep[src] = dep[par] + 1, anc[src][0] = par;
	for (int i = 1; i <= ceil(log2(N)); i++) anc[src][i] = anc[anc[src][i - 1]][i - 1];
	for (int i = head[src]; i; i = edges[i].nxt){
		int v = edges[i].v;
		if (v == par) continue;
		if (in[v]) low[src] = min(low[src], in[v]);
		else dfs(v, src), low[src] = min(low[src], low[v]);
	}
	out[src] = t;
}
int find(int u, int v){
	for (int i = ceil(log2(N)); i >= 0; i--)
		if (dep[v] - (1 << i) > dep[u]) v = anc[v][i];
	return v;
}
bool isanc(int u, int v){return in[u] <= in[v] && out[u] >= out[v];}
int main(){
	N = re, E = re;
	for (int i = 0; i < E; i++){
		int a = re, b = re;
		edges[++tot] = {b, head[a]}, head[a] = tot;
		edges[++tot] = {a, head[b]}, head[b] = tot;
	}
	dfs(1, 0);
	Q = re;
	while(Q--){
		if (re == 1){
			int A = re, B = re, G1 = re, G2 = re;
			if (isanc(G2, G1)) swap(G1, G2);
			if (low[G2] <= in[G1]) puts("yes");
			else if ((isanc(G2, A) ^ isanc(G2, B)) && (isanc(G1, A) || isanc(G1, B))) puts("no");
			else puts("yes");
		} else {
			int A = re, B = re, C = re;
			if (isanc(C, A) ^ isanc(C, B)){
				if (isanc(C, B)) swap(A, B);
				int x = find(C, A);
				if (low[x] >= in[C]) puts("no");
				else puts("yes");
			} else if (isanc(C, A) && isanc(C, B)){
				int l = find(C, A), r = find(C, B);
				if (l == r) puts("yes");
				else if (low[l] >= in[C] || low[r] >= in[C] || C == 1) puts("no");
				else puts("yes");
			} else puts("yes");
		}
	}
}

