#include <bits/stdc++.h>
using namespace std;
int n, x, a[20], dp[1<<20], dp1[1<<20];
int main(){
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 1, dp1[0] = x;
    for (int msk = 0; msk < (1 << n); msk++){
        for (int i = 0; i < n; i++){
            if (msk >> i & 1) continue;
            int nmsk = msk | (1 << i), ndp = -1, ndp1 = -1;
            if (dp1[msk] >= a[i]) ndp = dp[msk], ndp1 = dp1[msk] - a[i];
            else ndp = dp[msk] + 1, ndp1 = x - a[i];
            if (ndp < dp[nmsk]) dp[nmsk] = ndp, dp1[nmsk] = ndp1;
            else if (ndp == dp[nmsk] && ndp1 > dp1[nmsk]) dp1[nmsk] = ndp1;
        }
    }
    cout << dp[(1 << n) - 1] << '\n';
}
