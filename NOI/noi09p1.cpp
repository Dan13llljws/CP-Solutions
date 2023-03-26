#include <stdio.h>
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e4 + 5;
int n, d, t, tot, ce, cn, a[MM], b[MM], in[MM], vis[MM], ans[MM], q[MM], nxt[MM<<1], v[MM<<1], w[MM<<1], head[MM<<1]; 
int main(){
    n = re;
    for (int i = 0; i < n; i++){
        d = re, a[i] = (i + d) % n, b[i] = (i - d + n) % n, in[a[i]]++, in[b[i]]++;
        nxt[++tot] = head[a[i]], v[tot] = b[i], w[tot] = i, head[a[i]] = tot;
        nxt[++tot] = head[b[i]], v[tot] = a[i], w[tot] = i, head[b[i]] = tot;
    }
    for (int i = 0; i < n; i++)
        if (in[i] == 1) q[t++] = i;
    for (int i = 0; i < t; i++){
        int u = q[i]; cn++;
        for (int j = head[u]; j; j = nxt[j]){
            if (!vis[w[j]]) ce++, ans[w[j]] = u, vis[w[j]] = 1;
            if (--in[v[j]] == 1) q[t++] = v[j];
        }
    }
    if (ce != cn) return 0 * puts("No Answer");
    for (int i = 0; i < n; i++){
        if (vis[i]) continue;
        vis[i] = 1;
        int src = ans[i] = a[i] < b[i] ? a[i] : b[i];
        while(1){
            for (int j = head[src]; j; j = nxt[j])
                if (!vis[w[j]]){vis[w[j]] = 1, ans[w[j]] = src = v[j]; break;}
            if (src == a[i] || src == b[i]) break;
        }
    }
    for (int i = 0; i < n; i++) printf("%d ", ans[i]);
}

