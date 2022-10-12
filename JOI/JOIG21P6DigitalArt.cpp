#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1005, MN = 300;
int n, m, s, tot, ans, g[MM][MM], a[MN], b[MN], c[MN], d[MN], f[MN], col[MN]; priority_queue<int> q;
int main(){
    n = re, m = re, s = re, memset(a, 0x3f, sizeof a), memset(b, 0x3f, sizeof b);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            int x = re; g[i][j] = x, f[x] = 1;
            a[x] = min(i, a[x]), b[x] = min(j, b[x]);
            c[x] = max(i, c[x]), d[x] = max(j, d[x]);
        }
    for (int i = 1; i <= 256; i++) 
        if (f[i]) col[tot++] = i;
    sort(col, col + tot, [](int x, int y){return d[x] < d[y];});
    for (int i = 0; i < tot; i++)
        for (int j = 0; j < tot; j++){
            int x = col[i], y = col[j];
            if (a[x] > a[y] || c[x] > c[y]) continue;
            int len = s / (c[y] - a[x] + 1);
            if (!len) continue;
            for (int k = 0; k < tot; k++){
                int cur = col[k];
                if (a[cur] < a[x] || c[cur] > c[y]) continue;
                q.push(-b[cur]);
                while(q.size() && -q.top() <= d[cur] - len) q.pop();
                ans = max(ans, (int)q.size());
            } while(q.size()) q.pop();
        }
    printf("%d\n", tot - ans);
}
