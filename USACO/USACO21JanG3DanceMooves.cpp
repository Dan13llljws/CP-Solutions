#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e5 + 5;
int n, k, tot, cnt, len, f[MM], pos[MM], c[MM], vis[MM], ans[MM]; ll m;
int head[MM*5], v[MM*5], nxt[MM*5], w[MM*5], cycle[MM];
void upd(int x, int y){
    f[x] += y;
    if (y == 1 && f[x] == 1) cnt++;
    if (y == -1 && !f[x]) cnt--;
}
int main(){
    n = re, k = re, m = re;
    for (int i = 1; i <= n; i++) c[i] = i, nxt[++tot] = head[i], v[tot] = i, head[i] = tot;
    for (int i = 0; i < k; i++){
        int a = re, b = re; swap(c[a], c[b]);
        nxt[++tot] = head[c[a]], v[tot] = a, w[tot] = i, head[c[a]] = tot;
        nxt[++tot] = head[c[b]], v[tot] = b, w[tot] = i, head[c[b]] = tot; 
    }
    for (int i = 1; i <= n; i++) pos[c[i]] = i;
    for (int i = 1; i <= n; i++){
        if (vis[i]) continue;
        len = 0, cnt = 0; ll d = m / k, r = m % k;
        for (int j = i; !vis[j]; vis[j] = 1, j = pos[j]) cycle[len++] = j;
        if (d > len) d = len, r = 0;
        for (int j = 0; j < d; j++) 
            for (int i1 = head[cycle[j]]; i1; i1 = nxt[i1]) upd(v[i1], 1);
        for (int j = 0, j1 = d; j < len; j++, j1++){
            if (j1 >= len) j1 = 0;
            for (int i1 = head[cycle[j1]]; i1; i1 = nxt[i1]) 
                if (w[i1] < r) upd(v[i1], 1);
            ans[cycle[j]] = cnt;
            for (int i1 = head[cycle[j1]]; i1; i1 = nxt[i1])
                if (w[i1] >= r) upd(v[i1], 1);
            for (int i1 = head[cycle[j]]; i1; i1 = nxt[i1]) upd(v[i1], -1);
        }
        for (int j = 0; j < len; j++)
            for (int i1 = head[cycle[j]]; i1; i1 = nxt[i1]) f[v[i1]] = 0;
    }
    for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
}
