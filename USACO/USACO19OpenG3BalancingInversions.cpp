#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 2e5 + 5;
int n, a[MM], lft[MM], rit[MM]; ll L, R, l, r, cur, ans = 1e18;
int main(){
    n = re;
    for (int i = 1; i <= n; i++){
        lft[i] = lft[i - 1] + (a[i] = re);
        if (!a[i]) L += lft[i];
    }
    for (int i = 1; i <= n; i++) a[i + n] = re;
    for (int i = n; i; i--){
        rit[i + n] = rit[i + n + 1] + !a[i + n];
        if (a[i + n]) R += rit[i + n];
    } l = L, r = R, ans = abs(r - l);
    for (int i = n, j = n + 1;; j++, i--){
        while(i && !a[i]) i--;
        while(j <= 2 * n && a[j]) j++;
        if (!i || j > 2 * n) break;
        cur += j - i, l += lft[i] - n + i, r += rit[j] - j + n + 1, ans = min(ans, cur + abs(r - l));
    } l = L, r = R, cur = 0;
    for (int i = n, j = n + 1;; j++, i--){
        while(i && a[i]) i--;
        while(j <= 2 * n && !a[j]) j++;
        if (!i || j >  2 * n) break;
        cur += j - i, l -= lft[i], r -= rit[j], ans = min(ans, cur + abs(r - l));
    } printf("%lld\n", ans);
}
