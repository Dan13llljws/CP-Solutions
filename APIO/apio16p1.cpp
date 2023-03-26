#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 505, mod = 1e9 + 7;
int n, t, a[MM], b[MM], c[MM*2], dp[MM]; ll inv[MM];
ll fpow(ll a, ll b){
    ll ret = 1;
    while(b){
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod, b >>= 1;
    } return ret;
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]), c[t++] = a[i] - 1, c[t++] = b[i];
    for (int i = 1; i <= n; i++) inv[i] = fpow(i, mod - 2);
    sort(c, c + t), t = unique(c, c + t) - c, dp[0] = 1;
    for (int i = 1; i < t; i++){
        for (int j = n; j; j--){
            if (c[i] > b[j] || c[i] < a[j]) continue;
            int m = c[i] - c[i - 1], cnt = 1; ll p = m;
            for (int k = j - 1; k >= 0; k--){
                if (a[k] <= c[i - 1]) dp[j] = (dp[j] + p * dp[k]) % mod;
                if (c[i] >= a[k] && c[i] <= b[k]) p = p * ++m % mod * inv[++cnt] % mod;
            }
        }
    } int ans = 0;
    for (int i = 1; i <= n; i++) ans = (ans + dp[i]) % mod;
    printf("%d\n", ans);
}
