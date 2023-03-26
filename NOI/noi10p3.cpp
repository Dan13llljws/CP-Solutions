#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 505*505, MN = 1002005;
int n, m, ans, tot, head[MM], v[MN], w[MN], nxt[MN], d[MM]; priority_queue<pair<int,int>> q;
int get(int x, int y){return x * (n + 2) + y;}
void add(int a, int b, int c){nxt[tot] = head[a], v[tot] = b, w[tot] = c, head[a] = tot++;}
void djk(){
    while(q.size()){
        int u = q.top().second, dis = -q.top().first; q.pop();
        if (d[u] > dis) continue;
        for (int i = head[u]; i != -1; i = nxt[i])
            if (d[v[i]] > d[u] + w[i]) d[v[i]] = d[u] + w[i], q.push({-d[v[i]], v[i]});
    }
}
int main(){
    n = re, memset(head, -1, sizeof head);
    for (int i = 1; i <= n + 1; i++)
        for (int j = 1; j <= n; j++) add(get(i - 1, j), get(i, j), re);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n + 1; j++) add(get(i, j), get(i, j - 1), re);
    for (int i = 1; i <= n + 1; i++)
        for (int j = 1; j <= n; j++) add(get(i, j), get(i - 1, j), re);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n + 1; j++) add(get(i, j - 1), get(i, j), re);
    memset(d, 0x3f, sizeof d); ans = 1e9;
    for (int i = 1; i <= n; i++) q.push({0, i}), d[i] = 0;
    djk();
    for (int i = 1; i <= n; i++) ans = min(ans, d[get(n + 1, i)]);
    for (int i = 1; i <= n; i++) ans = min(ans, d[get(i, 0)]);
    memset(d, 0x3f, sizeof d); 
    for (int i = 1; i <= n; i++) q.push({0, get(i, n + 1)}), d[get(i, n + 1)] = 0;
    djk();
    for (int i = 1; i <= n; i++) ans = min(ans, d[get(i, 0)]);
    for (int i = 1; i <= n; i++) ans = min(ans, d[get(n + 1, i)]);
    printf("%d\n", ans);
}
