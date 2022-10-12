#include <stdio.h>
const int mod = 1024523, MM = 505;
int n, m, cur, dp[2][MM][MM]; char a[MM], b[MM];
void add(int &a, int b){a += b; if (a >= mod) a -= mod;}
int main(){
    scanf("%d%d %s %s", &n, &m, a, b);
    dp[0][0][0] = 1;
    for (int i = 0; i <= n; i++, cur ^= 1)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= i + j && k <= n; k++){
                if (!dp[cur][j][k]) continue;
                if (a[i] == a[k]) add(dp[cur ^ 1][j][k + 1], dp[cur][j][k]);
                if (b[j] == a[k]) add(dp[cur][j + 1][k + 1], dp[cur][j][k]);
                if (a[i] == b[i + j - k]) add(dp[cur ^ 1][j][k], dp[cur][j][k]);
                if (b[j] == b[i + j - k]) add(dp[cur][j + 1][k], dp[cur][j][k]);
                dp[cur][j][k] = 0;
            }
    printf("%d\n", dp[cur][m][n]);
}
