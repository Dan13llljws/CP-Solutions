#include <bits/stdc++.h>
using namespace std;
const int MM = 3e5 + 5;
int ans, n[2], k, a[2][MM], b[2][MM], dp[2*MM][2][2]; priority_queue<array<int,4>> q;
int main(){
    scanf("%d%d%d", &n[0], &n[1], &k);
    for (int j : {0, 1}){
        for (int i = 0; i < n[j]; i++) scanf("%d%d", a[j] + i, b[j] + i);
        sort(a[j], a[j] + n[j]), sort(b[j], b[j] + n[j]);
    } memset(dp, 0x3f, sizeof dp), dp[!a[0][0]][0][0] = 0, q.push({0, !a[0][0], 0, 0});
    while(q.size()){
        auto cur = q.top(); q.pop();
        int t = -cur[0], c = cur[1], p = cur[2], seen = cur[3];
        ans = max(ans, c); int r = !p;
        int u[2] = {upper_bound(b[0], b[0] + n[0], t) - b[0], upper_bound(b[1], b[1] + n[1], t) - b[1]};
        if (c == 0) u[0] = -1;
        int v = upper_bound(a[p], a[p] + n[p], t) - a[p];
        if (v < n[p]){
            int nt = max(t, a[p][v]), vis = 0;
            if (upper_bound(b[r], b[r] + n[r], nt) - b[r] == u[r]) vis = seen;
            if (dp[c + 1][p][vis] > nt) dp[c + 1][p][vis] = nt, q.push({-nt, c + 1, p, vis});
        }
        t += k, v = upper_bound(b[r], b[r] + n[r], t) - b[r];
        if (v < n[r]){
            int nt = max(t, a[r][v]), vis = 0, nc = c + !(v == u[r] && seen);
            if (upper_bound(b[p], b[p] + n[p], nt) - b[p] == u[p]) vis = 1;
            if (dp[nc][r][vis] > nt) dp[nc][r][vis] = nt, q.push({-nt, nc, r, vis});
        }
    }
    printf("%d\n", ans);
}
