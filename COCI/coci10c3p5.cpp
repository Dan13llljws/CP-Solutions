#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 3e5 + 5;
int n, ts, tt, a[MM], s[MM], t[MM]; ll ans;
int main(){
    n = re;
    for (int i = 1; i <= n; i++){
        a[i] = re;
        while(ts && a[i] >= a[s[ts]]) ans += 1LL * a[s[ts]] * (i - s[ts]) * (s[ts] - s[ts - 1]), ts--;
        while(tt && a[i] <= a[t[tt]]) ans -= 1LL * a[t[tt]] * (i - t[tt]) * (t[tt] - t[tt - 1]), tt--;
        s[++ts] = i, t[++tt] = i;
    } 
    while(ts) ans += 1LL * a[s[ts]] * (n - s[ts] + 1) * (s[ts] - s[ts - 1]), ts--;
    while(tt) ans -= 1LL * a[t[tt]] * (n - t[tt] + 1) * (t[tt] - t[tt - 1]), tt--;
    printf("%lld\n", ans);
}
