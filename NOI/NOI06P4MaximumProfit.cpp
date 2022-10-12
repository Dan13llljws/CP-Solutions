#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 55005, MN = 310005;
int n, m, flow, ans, tot, sum, dep[MM], cur[MM], head[MM], nxt[MN], v[MN], w[MN]; 
int bfs(){
    queue<int> q; q.push(0); memset(dep, 0, sizeof dep); dep[0] = 1;
    while(q.size()){
        int u = q.front(); q.pop();
        for (int i = head[u]; i != -1; i = nxt[i]){
            int to = v[i];
            if (!dep[to] && w[i])
                dep[to] = dep[u] + 1, q.push(to);
        }
    } return dep[n + m + 1];
}
int dfs(int src, int dis){
    if (src == n + m + 1) return dis;
    for (int& i = cur[src]; i != -1; i = nxt[i])
        if (dep[v[i]] == dep[src] + 1 && w[i]){
            int d = dfs(v[i], min(dis, w[i]));
            if (d){w[i] -= d, w[i ^ 1] += d; return d;}
        }
    return 0;
}
void adde(int a, int b, int c){
    nxt[tot] = head[a], v[tot] = b, w[tot] = c, head[a] = tot++;
    nxt[tot] = head[b], v[tot] = a, w[tot] = 0, head[b] = tot++;
}
int main(){
    n = re, m = re; memset(head, -1, sizeof head);
    for (int i = 1; i <= n; i++) adde(0, i, re);
    for (int i = 1; i <= m; i++){
        int a = re, b = re, c = re; sum += c;
        adde(a, i + n, 1e9), adde(b, i + n, 1e9), adde(i + n, n + m + 1, c);
    }
    while(bfs()){
        for (int i = 0; i <= n + m + 1; i++) cur[i] = head[i];
        while(flow = dfs(0, 1e9)) ans += flow;
    } printf("%d\n", sum - ans);
}
