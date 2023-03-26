#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e6 + 5;
int n, k, t, h[505], dp[505][505]; ll fac[MM], inv[MM];
ll f(int a, int b, int c){
    return fac[a] * fac[b] % mod * inv[a - c] % mod * inv[b - c] % mod * inv[c] % mod;
}
ll fpow(ll a, int b){
    ll ret = 1;
    while(b){
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod, b >>= 1;
    } return ret;
}
int build(int l, int r, int lvl){
    int mn = 1e9, pre = l - 1, cur = ++t, x, y;
    for (int i = l; i <= r; i++) mn = min(mn, h[i]);
    dp[cur][0] = 1, x = r - l + 1, y = mn - lvl + 1;
    for (int i = l; i <= r + 1; i++)
        if (h[i] == mn || i == r + 1){
            if (pre < i - 1){
                int v = build(pre + 1, i - 1, mn + 1);
                for (int j = min(x, k); j; j--)
                    for (int j1 = 1; j1 <= j; j1++)
                        dp[cur][j] = (dp[cur][j] + 1LL * dp[v][j1] * dp[cur][j - j1]) % mod;
            } pre = i;
        }
    for (int i = min(x, k); i; i--)
        for (int j = 1; j <= min(x, y); j++)
            dp[cur][i] = (dp[cur][i] + 1LL * dp[cur][i - j] * f(x - i + j, y, j)) % mod;
    return cur;
}
int main(){
    n = re, k = re, fac[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++) h[i] = re;
    for (int i = 1; i <= 1e6; i++) fac[i] = fac[i - 1] * i % mod;
    inv[1000000] = fpow(fac[1000000], mod - 2);
    for (int i = 999999; i; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
    build(1, n, 1); printf("%d\n", dp[1][k]);
}
