#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, 1e18));
    dp[0][0] = 0;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
    auto sqr = [&](ll x) -> ll{
        return x * x;
    };
    auto check = [&](int i, int j, int k, int l) -> bool{ // j > k > l
        return dp[i][k] + sqr(a[j] - a[k]) <= dp[i][l] + sqr(a[j] - a[l]);
    };
    auto better = [&](int i, int j, int k, int l) -> bool{ // j > k > l
        return (dp[i][j] + sqr(a[j]) - dp[i][k] - sqr(a[k])) * (a[j] - a[l]) <=
               (dp[i][j] + sqr(a[j]) - dp[i][l] - sqr(a[l])) * (a[j] - a[k]);
    };
    for (int i = 1; i <= k; i++){
        deque<int> q;
        q.push_back(0);
        for (int j = 1; j <= n; j++){
            while(q.size() > 1 && check(i - 1, j, q[1], q[0])) q.pop_front();
            dp[i][j] = dp[i - 1][q[0]] + (a[j] - a[q[0]]) * (a[j] - a[q[0]]);
            while(q.size() > 1 && better(i - 1, j, q.back(), q[q.size() - 2])) q.pop_back();
            q.push_back(j);
        }
    }
    cout << dp[k][n] << '\n';
}
