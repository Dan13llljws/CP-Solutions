#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 505, mod = 1e9 + 7;
ll fac[MM], inv[MM];
ll fpow(ll a, ll b){
    ll ret = 1;
    while(b){
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod, b >>= 1;
    } return ret;
}
void init(){
    // inv: 1/fac
    fac[0] = 1, inv[0] = 1;
    for (int i = 1; i < MM; i++){
        fac[i] = i * fac[i - 1] % mod;
        inv[i] = fpow(fac[i], (mod - 2));
    }
}

long long choose(int a, int b){
    return fac[a] * inv[b] % mod * inv[a - b] % mod;
}
char s[MM]; ll dp[MM][MM];
int main(){
    scanf("%s", s + 1);
    init();
    int n = strlen(s + 1);
    for (int i = 0; i <= n; i++) dp[i + 1][i] = 1;
    for (int len = 2; len <= n; len += 2){
        for (int l = 1, r = len; r <= n; l++, r++){
            for (int i = l + 1; i <= r; i += 2)
                if (s[l] == s[i]) 
                    dp[l][r] = (dp[l][r] + dp[l + 1][i - 1] * dp[i + 1][r] % mod * choose((r - l + 1) / 2, (r - i) / 2)) % mod;
        }
    }
    printf("%d\n", dp[1][n]);
}
// remove n char, n / 2 ops;
// dp[l][r] = number of ways to remove that range. 
// loop throu all i
// [l, i]  and  [i + 1, r]
// remove a[l] and a[i]
// [l + 1, i - 1] is removed, and [i + 1, r] removed
// a[l] == a[i]
