#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll count_tastiness(ll x, vector<ll> a){
    int k = a.size();
    vector<ll> sum(60); unordered_map<ll,ll> dp;
    for (int i = 0; i < k; i++) sum[i] = a[i] * (1LL << i);
    for (int i = 1; i < 60; i++) sum[i] += sum[i - 1];
    function<ll(ll)> dfs = [&](ll i){
        if (i < 0) return 0LL;
        if (i == 0) return 1LL;
        if (dp.count(i)) return dp[i];
        int j = 63 - __builtin_clzll(i);
        return dp[i] = dfs((1LL << j) - 1) + dfs(min(i, sum[j] / x) - (1LL << j));
    }; return dfs((1LL << 60) - 1);
}
int main(){}

