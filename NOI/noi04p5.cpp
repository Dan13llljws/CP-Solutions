#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m; double k1, k2, ans;
int sqr(int x){return x * x;}
double calc(int x, int len, double k){
    int t = len % x, w = len / x;
    return k * (sqr(w) * (x - t) + sqr(w + 1) * t);
}
int main(){
    scanf("%lf%lf%d%d", &k1, &k2, &n, &m); ans = 1e9;
    if (m % n == 0) return 0 * printf("%.1f\n", calc(n, 100, k1) + calc(m, 100, k2));
    int tl = n - m % n, tr = m % n, bl = m / n, br = m / n + 1;
    for (int i = bl * tl; i + br * tr <= 100; i++)
        ans = min(ans, calc(tl, i, k1) + calc(tr, 100 - i, k1) + calc(bl * tl, i, k2) + calc(br * tr, 100 - i, k2));
    printf("%.1f\n", ans);
}
