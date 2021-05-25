#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1005;
int n, m, t, g[MM][MM], h[MM], st[MM]; ll ans;
int main(){
    n = re, m = re;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++)
            g[i][j] = re;
    for (int i = 1; i <= n; i++, t = 1){
        for (int j = 1; j <= m; j++)
            if (g[i][j] == g[i - 1][j]) h[j]++;
            else h[j] = 1;
        for (int j = 1, sum = 0; j <= m; j++){
            if (g[i][j] != g[i][j - 1]) t = 0, sum = 0, st[0] = j - 1;
            while(t && h[st[t]] >= h[j]) sum -= (h[st[t]] - h[j]) * (st[t] - st[t - 1]), t--;
            sum += h[j], ans += sum, st[++t] = j;
        }
    } printf("%lld\n", ans);
}
