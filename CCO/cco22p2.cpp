#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6 + 5;
typedef long long ll;
int n; ll ans, worse[MM], b[MM], p[MM], u[MM], l[MM], r[MM], m[MM];
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", b + i);
    for (int i = 2; i <= n; i++) scanf("%lld", p + i);
    for (int i = 2; i <= n; i++) scanf("%lld", u + i);
    worse[n] = b[n];
    for (int i = n - 1; i; i--){
        if (worse[i + 1] + b[i] + u[i + 1] < p[i + 1]){
            puts("NO");
            return 0;
        } worse[i] = b[i] - max(0LL, p[i + 1] - worse[i + 1] - u[i + 1]);
    }
    puts("YES");
    ll pb = b[1];
    for (int i = 2; i <= n; i++){
        ans += m[i] = max(0LL, p[i] - pb - worse[i]);
        l[i] = min(p[i], pb), r[i] = p[i] - l[i] - m[i], pb = b[i] - r[i];
    }
    printf("%lld\n", ans);
    for (int i = 2; i <= n; i++) printf("%lld %lld %lld\n", l[i], m[i], r[i]);
}
