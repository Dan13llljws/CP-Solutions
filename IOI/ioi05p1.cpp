#include <bits/stdc++.h>
using namespace std;
const int MM = 255;
int n, m, q, k, dp[MM], g[MM][MM], h[MM][MM], ans = 1e9;
int main(){
    scanf("%d%d%d%d", &n, &m, &q, &k), dp[0] = 1e9;
    for (int i = 0, x, y; i < q; i++) scanf("%d%d", &x, &y), g[x][y]++;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            h[i][j] = h[i - 1][j] + g[i][j];
    for (int r = 1; r <= n; r++){
        dp[r] = 1e9;
        for (int l = r; l; l--){
            for (int i = 1, j = 1, s = 0; i <= m; i++){
                s += h[r][i] - h[l - 1][i]; 
                while(s - h[r][j] + h[l - 1][j] >= k) s -= h[r][j] - h[l - 1][j], j++; 
                if (s == k) dp[r] = min(dp[r], r + i - l - j + 2);
            } ans = min(ans, dp[r] + dp[l - 1]);
        } dp[r] = min(dp[r], dp[r - 1]);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            h[i][j] = h[i][j - 1] + g[i][j];
    for (int r = 1; r <= m; r++){
        dp[r] = 1e9;
        for (int l = r; l; l--){
            for (int i = 1, j = 1, s = 0; i <= n; i++){
                s += h[i][r] - h[i][l - 1];
                while(s - h[j][r] + h[j][l - 1] >= k) s -= h[j][r] - h[j][l - 1], j++;
                if (s == k) dp[r] = min(dp[r], r + i - l - j + 2);
            } ans = min(ans, dp[r] + dp[l - 1]); 
        } dp[r] = min(dp[r], dp[r - 1]);
    } 
    if (ans == 1e9) puts("NO");
    else printf("%d\n", ans << 1);
}
