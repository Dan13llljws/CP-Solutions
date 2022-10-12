#include <stdio.h>
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e5 + 5;
int n, m, q, t, tot, bit[MM<<1], lst[MM], anc[17][MM], head[MM], nxt[MM<<1], v[MM<<1], in[MM], out[MM], on[MM], x[MM], y[MM], ans[MM]; 
void upd(int p, int a){
    for (; p <= 2 * n; p += p & -p) bit[p] += a;
}
int get(int p){
    int ret = 0;
    for (; p; p -= p & -p) ret += bit[p];
    return ret;
}
void dfs(int src, int par){
    upd(in[src] = ++t, 1);
    for (int i = 1; i < 17; i++) anc[i][src] = anc[i - 1][anc[i - 1][src]];
    for (int i = head[src]; i; i = nxt[i])
        if (v[i] != par) anc[0][v[i]] = src, dfs(v[i], src);
    upd(out[src] = ++t, -1);
}
int up(int u){
    for (int i = 16; i >= 0; i--)
        if (anc[i][u] && get(in[u]) == get(in[anc[i][u]])) u = anc[i][u];
    return u;
}
int main(){
    n = re, m = re, q = re;
    for (int i = 1; i < n; i++){
        x[i] = re, y[i] = re;
        nxt[++tot] = head[x[i]], v[tot] = y[i], head[x[i]] = tot;
        nxt[++tot] = head[y[i]], v[tot] = x[i], head[y[i]] = tot;
    } dfs(1, 1);
    for (int i = 1; i <= n; i++) ans[i] = 1;
    for (int i = 1; i < n; i++)
        if (anc[0][y[i]] == x[i]) x[i] ^= y[i], y[i] ^= x[i], x[i] ^= y[i];
    for (int i = 0; i < m; i++){ 
        int e = re;
        if (on[e]) lst[x[e]] = ans[x[e]] = ans[up(y[e])], upd(in[x[e]], 1), upd(out[x[e]], -1), on[e] = 0;
        else ans[up(y[e])] += ans[x[e]] - lst[x[e]], upd(in[x[e]], -1), upd(out[x[e]], 1), on[e] = 1;
    } 
    for (int i = 1; i <= n; i++) ans[i] = ans[up(i)];
    while(q--) printf("%d\n", ans[re]);
}
