#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    long long n;
    cin >> n;
    n++;
    long long p = 2, ans = 0;
    for (int i = 0; i < 60; i++, p <<= 1){
        ans += n / p * (p >> 1);
        ans += max(0LL, n % p - (p >> 1)); 
    }
    cout << ans << '\n';
}
