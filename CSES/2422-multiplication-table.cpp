#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    ll l = 1, r = 1LL * n * n;
    while(l < r){
        ll mid = (l + r) >> 1;
        ll k = 0;
        for (int i = 1; i <= n; i++) k += min(1LL * n, mid / i);
        if (k > 1LL * n * n / 2) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
}

