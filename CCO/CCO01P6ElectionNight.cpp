#include <bits/stdc++.h>
using namespace std;
const int MM = 205;
int n, m, ans, flow, cur, c[MM][MM], b[MM], w[MM], pre[MM]; vector<int> f[MM];
int bfs(){
    queue<pair<int,int>> q; q.push({0, 1e9}), memset(pre, -1, sizeof pre), pre[0] = -2;
    while(q.size()){
        int u = q.front().first, d = q.front().second; q.pop();
        if (u == n + m + 1) return d;
        for (int v = 1; v <= n + m + 1; v++)
            if (c[u][v] && pre[v] == -1)
                pre[v] = u, q.push({v, min(d, c[u][v])});
    } return 0;
}
int main(){
    while(scanf("%d%d", &n, &m), n){ 
        memset(w, 0, sizeof w); memset(b, 0, sizeof b);
        for (int i = 1, k; i <= n; i++){
            scanf("%d", &k); f[i].resize(k);
            for (int j = 0; j < k; j++){
                scanf("%d", &f[i][j]), w[f[i][j]]++;
                if (k == 1) b[f[i][j]]++;
            }
        }
        for (int i = 1; i <= m; i++){
            bool def = 1;
            for (int j = 1; j <= m; j++)
                if (j != i) def &= w[j] < b[i];
            if (def){printf("Candidate %d will become president.\n", i); continue;}
            memset(c, 0, sizeof c), ans = 0;
            for (int j = n + 1; j <= n + m; j++) c[j][n + m + 1] = w[i] - 1;
            for (int j = 1; j <= n; j++) 
                if (find(f[j].begin(), f[j].end(), i) == f[j].end()){
                    c[0][j] = 1;
                    for (int k : f[j]) c[j][k + n] = 1;
                }
    //         for (int j = 0; j <= n + m + 1; j++, puts(""))
    //             for (int k = 0; k <= n + m + 1; k++) printf("%d ", c[j][k]);
    // 
            while(flow = bfs()){
                ans += flow, cur = n + m + 1;
    //             printf("%d\n", flow);
                while(cur){
                    int p = pre[cur];
                    c[cur][p] += flow, c[p][cur] -= flow, cur = p;
                }
            } printf("Candidate %d %s become president.\n", i, ans == n - w[i] ? "may" : "will not");
        }
    }
        
}
