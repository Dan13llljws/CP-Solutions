#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> s(n), f(n);
    for (int &x : s) cin >> x;
    for (int &x : f) cin >> x;
    s.insert(s.begin(), 0), f.insert(f.begin(), x);
    deque<int> q;
    vector<long long> dp(n + 1, 1e9);
    dp[0] = 0;
    q.push_back(0);
    auto check = [&](int i, int j, int k){
        return dp[k] + 1LL * s[i] * f[k] > dp[j] + 1LL * s[i] * f[j];
    };
    auto better = [&](int i, int j, int k){
        return (dp[i] - dp[j]) * (f[k] - f[i]) <= (dp[i] - dp[k]) * (f[j] - f[i]);
    };
    for (int i = 1; i <= n; i++){
        while(q.size() > 1 && check(i, q[1], q[0])) q.pop_front();
        dp[i] = dp[q[0]] + 1LL * s[i] * f[q[0]];
        while(q.size() > 1 && better(i, q.back(), q[q.size() - 2])) q.pop_back();
        q.push_back(i);
        cout << endl;
    }
    cout << dp[n] << '\n';
}
