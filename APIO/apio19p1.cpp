#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
int n; ll a, b, len, ans; vector<pair<ll,ll>> f; 
int main(){
    n = re, a = re, b = re, len = a / __gcd(a, b + 1) * b;
    for (int i = 0; i < n; i++){
        ll l = re, r = re;
        if (r - l + 1 >= len) return 0 * printf("%lld\n", len);
        l %= len, r %= len;
        if (l > r) f.push_back({0, r}), f.push_back({l, len - 1});
        else f.push_back({l, r});
    } sort(f.begin(), f.end()); ll l = f[0].first, r = f[0].second;
    for (int i = 1; i < (int)f.size(); i++){
        if (f[i].first > r) ans += r - l + 1, l = f[i].first, r = f[i].second;
        else r = max(r, f[i].second);
    } ans += r - l + 1, printf("%lld\n", ans);
}
