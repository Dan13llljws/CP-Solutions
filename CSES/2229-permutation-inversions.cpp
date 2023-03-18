#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> dp(k + 2);
    dp[0] = 1;
    auto add = [&](int &a, int b){
        a += b;
        if (a >= mod) a -= mod;
    };
    auto sub = [&](int &a, int b){
        a -= b;
        if (a < 0) a += mod;
    };
    for (int i = 0; i < n; i++){
        vector<int> dp1(k + 2);
        for (int j = 0; j <= k; j++)
            add(dp1[j], dp[j]), sub(dp1[min(k, j + i) + 1], dp[j]);
        for (int j = 1; j <= k; j++) add(dp1[j], dp1[j - 1]);
        dp = dp1;
    }
    cout << dp[k] << '\n';
}
