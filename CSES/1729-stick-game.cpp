#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> p(k);
    for (int &x : p) cin >> x;
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++){
        for (int x : p)
            if (x <= i) dp[i] |= !dp[i - x];
        cout << (dp[i] ? 'W' : 'L');
    }
    cout << '\n';
}

