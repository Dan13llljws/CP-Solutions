#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> dp(1 << n);
    dp[(1 << n) - 1] = 1;
    for (int i = 1; i <= m; i++){
        for (int j = 0; j < n; j++){
            vector<int> ndp(1 << n);
            for (int mask = 0; mask < (1 << n); mask++){
                ndp[mask] = dp[mask ^ (1 << j)];
                if (j && (mask >> j & 1) && (mask >> (j - 1) & 1)) ndp[mask] += dp[mask ^ (1 << (j - 1))];
                if (ndp[mask] > mod) ndp[mask] -= mod;
            }
            dp = ndp;
        }
    }
    cout << dp[(1 << n) - 1] << '\n';
}




