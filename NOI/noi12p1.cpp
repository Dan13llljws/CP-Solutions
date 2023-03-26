#include <stdio.h>
typedef long long ll;
ll m, a, c, x, n, g, ans;
ll smul(ll o, ll k){
    ll ret = 0;
    while(k){
        if (k & 1) ret = (ret + o) % m;
        o = (o + o) % m, k >>= 1;
    } return ret;
}
ll fpow(ll o, ll k){
    ll ret = 1;
    while(k){
        if (k & 1) ret = smul(ret, o);
        o = smul(o, o), k >>= 1;
    } return ret;
}
ll geo(ll l, ll t){
    if (l == 1) return t;
    ll ret = geo(l / 2, t);
    ret = (ret + smul(ret, fpow(a, l / 2))) % m;
    if (l & 1) ret = (ret + smul(t, fpow(a, l - 1))) % m;
    return ret;
}
int main(){
    scanf("%lld%lld%lld%lld%lld%lld", &m, &a, &c, &x, &n, &g);
    printf("%lld\n", (smul(x, fpow(a, n)) + geo(n, c)) % m % g);
}
