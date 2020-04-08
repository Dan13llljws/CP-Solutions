#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
int n, c;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> c;
    int g = gcd(n, c);
    n /= g; c /= g;
    cout << (c - 1) * g;
    return 0;
}