#include <bits/stdc++.h>
using namespace std;
int n, cur, ans, dp[2][10][10]; 
int f(int x, int y){
    if (x == 9) return 1;
    return 1 + (y != x / 3) + (y != x % 3 && x % 3 != x / 3);
}
int g(int x, int y){
    if (x == 9) return y << 2;
    return x / 3 + 3 * y;
}
int main(){
    scanf("%d\n", &n); memset(dp, -1, sizeof dp); dp[0][9][9] = 0;
    for (int i = 0; i < n; i++, cur ^= 1){
        memset(dp[cur ^ 1], -1, sizeof dp[cur ^ 1]);
        char d = getchar(); int c = 0;
        if (d == 'M') c = 1;
        else if (d == 'F') c = 2;
        for (int a = 0; a < 10; a++)
            for (int b = 0; b < 10; b++){
                if (dp[cur][a][b] < 0) continue;
                dp[cur ^ 1][g(a, c)][b] = max(dp[cur ^ 1][g(a, c)][b], dp[cur][a][b] + f(a, c));
                dp[cur ^ 1][a][g(b, c)] = max(dp[cur ^ 1][a][g(b, c)], dp[cur][a][b] + f(b, c));
            }
    }
    for (int a = 0; a < 10; a++)
        for (int b = 0; b < 10; b++)
            ans = max(ans, dp[cur][a][b]);
    printf("%d\n", ans);
}


