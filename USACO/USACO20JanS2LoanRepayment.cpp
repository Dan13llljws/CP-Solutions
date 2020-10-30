#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, m, x, l, r, mid;
ll check(ll a){
    ll g = 0, days = k;
    while(days > 0 && g < n){
        ll y = (n - g) / a;
        if (y < m) return g + days * m;
        ll repday = (n - a * y - g) / y + 1;
        g += y * repday;    
        days -= repday;
    }
    return g;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("loan.in", "r", stdin); freopen("loan.out", "w", stdout);
    cin >> n >> k >> m;
    l = 1, r = 1e12;
    while(l <= r){
        mid = l + (r - l) / 2;
        if (check(mid) >= n){
            x = mid; l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << x;
    return 0;
}
