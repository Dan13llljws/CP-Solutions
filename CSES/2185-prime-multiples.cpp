#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n; int k;
    cin >> n >> k;
    vector<ll> a(k);
    for (ll &x : a) cin >> x;
    ll ans = 0;
    for (int mask = 1; mask < (1 << k); mask++){
        ll cur = n;
        for (int i = 0; i < k; i++) 
            if (mask >> i & 1) cur /= a[i];
        if (__builtin_popcount(mask) & 1) ans += cur;
        else ans -= cur;
    }
    cout << ans << '\n';
}
