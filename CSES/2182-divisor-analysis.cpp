#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
using ll = long long;
ll fpow(ll a, ll k){
    ll ret = 1;
    while(k){
        if (k & 1) ret = ret * a % mod;
        a = a * a % mod, k >>= 1;
    } return ret;
}
ll inv(ll x){
    return fpow(x, mod - 2);
}
 
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    long long a = 1, b = 1, c = 1, d = 1;
    vector<int> x(n), k(n);
    for (int i = 0; i < n; i++){
        cin >> x[i] >> k[i];
        a = a * (k[i] + 1) % mod;
        b = b * (fpow(x[i], k[i] + 1) - 1 + mod) % mod * inv(x[i] - 1) % mod;
        c = fpow(c, k[i] + 1) * fpow(fpow(x[i], 1LL * k[i] * (k[i] + 1) / 2), d) % mod;
        d = d * (k[i] + 1) % (mod - 1);
    }
    cout << a << ' ' << b << ' ' << c << '\n';
}
