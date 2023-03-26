#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, MM = 205;
int n, m, k, x, y, h, cur, ans, t, q[MM], dp[2][MM][MM], l[MM], r[MM], dir[MM]; char g[MM][MM];
int main(){
    scanf("%d%d%d%d%d", &n, &m, &x, &y, &k); memset(dp, -0x3f, sizeof dp);
    for (int i = 1; i <= n; i++) scanf("%s", g[i] + 1);
    for (int i = 1; i <= k; i++) scanf("%d%d%d", l + i, r + i, dir + i);
    dp[1][x][y] = 0;
    for (int c = 1; c <= k; c++, cur ^= 1){
        memset(dp[cur], -0x3f, sizeof dp[cur]);
        int len = r[c] - l[c] + 1; 
        if (dir[c] == 1){
            for (int i = 1; i <= m; i++){
                h = 1, t = 0;
                for (int j = n; j; j--){
                    if (g[j][i] == 'x'){h = 1, t = 0; continue;}
                    while(h <= t && q[h] - len > j) h++;
                    while(h <= t && dp[cur ^ 1][q[t]][i] + q[t] <= dp[cur ^ 1][j][i] + j) t--;
                    q[++t] = j, dp[cur][j][i] = dp[cur ^ 1][q[h]][i] + q[h] - j;
                }
            }
        } else if (dir[c] == 2){
            for (int i = 1; i <= m; i++){
                h = 1, t = 0;
                for (int j = 1; j <= n; j++){
                    if (g[j][i] == 'x'){h = 1, t = 0; continue;}
                    while(h <= t && q[h] + len < j) h++;
                    while(h <= t && dp[cur ^ 1][q[t]][i] - q[t] <= dp[cur ^ 1][j][i] - j) t--;
                    q[++t] = j, dp[cur][j][i] = dp[cur ^ 1][q[h]][i] + j - q[h];
                }
            }
        } else if (dir[c] == 3){
            for (int i = 1; i <= n; i++){
                h = 1, t = 0;
                for (int j = m; j; j--){
                    if (g[i][j] == 'x'){h = 1, t = 0; continue;}
                    while(h <= t && q[h] - len > j) h++;
                    while(h <= t && dp[cur ^ 1][i][q[t]] + q[t] <= dp[cur ^ 1][i][j] + j) t--;
                    q[++t] = j, dp[cur][i][j] = dp[cur ^ 1][i][q[h]] + q[h] - j;
                }
            }
        } else {
            for (int i = 1; i <= n; i++){
                h = 1, t = 0;
                for (int j = 1; j <= m; j++){
                    if (g[i][j] == 'x'){h = 1, t = 0; continue;}
                    while(h <= t && q[h] + len < j) h++;
                    while(h <= t && dp[cur ^ 1][i][q[t]] - q[t] <= dp[cur ^ 1][i][j] - j) t--;
                    q[++t] = j, dp[cur][i][j] = dp[cur ^ 1][i][q[h]] + j - q[h];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) 
            ans = max(ans, dp[cur ^ 1][i][j]);
    printf("%d\n", ans);
}
