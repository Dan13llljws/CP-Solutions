#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5, MOD = 1e9;
int n, m, k, dsu[4*MM], x[MM], y[MM], c[MM], pr[MM], pc[MM];
int find(int x){ return dsu[x] == x ? x : dsu[x] = find(dsu[x]); }
void unite(int x, int y){ dsu[find(x)] = find(y); }
int main(){
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; i++) scanf("%d%d%d", x + i, y + i, c + i), x[i]--, y[i]--;
    iota(dsu, dsu + 2 * (n + m), 0);
    memset(pc, -1, sizeof pc); memset(pr, -1, sizeof pr);
    int ans = 2;
    for (int i = 0; i < k; i++){
        if (x[i] == 0 && y[i] == 0) ans = 1;
        else if (y[i] == 0) unite(2 * x[i] + c[i], 0), unite(2 * x[i] + (c[i] ^ 1), 1);
        else if (x[i] == 0) unite(2 * n + 2 * y[i] + c[i], 0), unite(2 * n + 2 * y[i] + (c[i] ^ 1), 1);
        else {
            int p = (x[i] * y[i]) & 1 ^ c[i];
            unite(2 * x[i], (2 * n + 2 * y[i]) ^ p);
            unite((2 * x[i]) ^ 1, (2 * n + 2 * y[i]) ^ p ^ 1);
        }
    }
    if (find(0) == find(1)) ans = 0;
    for (int i = 1; i < n; i++)
        if (find(2 * i) == find(2 * i + 1)) ans = 0;
    for (int i = 1; i < m; i++)
        if (find(2 * n + 2 * i) == find(2 * n + 2 * i + 1)) ans = 0;
    for (int i = 1; i < n; i++){
        if (find(2 * i) == find(0) || find(2 * i + 1) == find(0)) continue;
        if (find(2 * i) == 2 * i) ans = ans * 2 % MOD;
    }
    for (int i = 1; i < m; i++){
        if (find(2 * n + 2 * i) == find(0) || find(2 * n + 2 * i + 1) == find(0)) continue;
        if (find(2 * n + 2 * i) == 2 * n + 2 * i) ans = ans * 2 % MOD;
    }
    printf("%d\n", ans);
}
