#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n, k, memo[250][250];
int rec(int n, int k){
    if (n < 0) return 0;
    if (k == 0 && n != 0) return 0;
    if (n == 0 && k != 0) return 1;
    if (memo[n][k]) return memo[n][k];
    return memo[n][k] = rec(n - k, k) + rec(n, k - 1);
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    cout << rec(n - k, k);
    return 0;
}