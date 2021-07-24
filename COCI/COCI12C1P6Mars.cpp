#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 512;
int n, k, cur, ans = 1e9, g[MM][MM], dp[2][MM][MM], tmp[MM][MM];
int main(){
    n = (1 << (k = re));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            g[i][j] = re;
    for (int i = 1; i <= k; i++, cur ^= 1){
        memset(dp[cur], 0x3f, sizeof dp[cur]), memset(tmp, 0x3f, sizeof tmp);
        for (int l = 0, r = (1 << i) - 1; l < n; l += (1 << i), r += (1 << i)){
            int mid = (l + r) >> 1;
            for (int a = l; a <= mid; a++)
                for (int b = l; b <= mid; b++)
                    for (int c = mid + 1; c <= r; c++)
                        tmp[a][c] = min(tmp[a][c], g[b][c] + dp[cur ^ 1][a][b]);
            for (int a = l; a <= mid; a++)
                for (int c = mid + 1; c <= r; c++)
                    for (int d = mid + 1; d <= r; d++)
                        dp[cur][a][d] = min(dp[cur][a][d], dp[cur ^ 1][c][d] + tmp[a][c]);
            for (int a = mid + 1; a <= r; a++)
                for (int b = l; b <= mid; b++)
                    dp[cur][a][b] = dp[cur][b][a];
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans = min(ans, dp[cur ^ 1][i][j]);
    printf("%d\n", ans);
}
