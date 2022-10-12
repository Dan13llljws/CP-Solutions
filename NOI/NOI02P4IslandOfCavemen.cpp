#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, s[20], p[20], l[20];
ll exgcd(ll a, ll b, ll &x, ll &y){
    if (!b){
        x = 1, y = 0;
        return a;
    } ll d = exgcd(b, a % b, y, x); y -= x * (a / b);
    return d;
}
int main(){
    scanf("%d", &n);
    if (n == 1) return 0 * puts("1");
    for (int i = 0; i < n; i++) scanf("%d%d%d", s + i, p + i, l + i), m = max(m, s[i]);
    for (;;m++){
        bool f = 1;
        for (int i = 0; i < n && f; i++)
            for (int j = i + 1; j < n; j++){
                ll a = p[i] - p[j], b = m, c = s[j] - s[i], x, y, d = exgcd(a, b, x, y);
                if (c % d) continue;
                x *= c / d, x %= b / d;
                if (x < 0) x += abs(b / d);
                if (x <= min(l[i], l[j])){f = 0; break;}
            }
        if (f) return 0 * printf("%d\n", m);
    }
}
