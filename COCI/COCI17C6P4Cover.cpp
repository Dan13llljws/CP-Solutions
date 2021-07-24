#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 5005;
int n, t, st[MM]; ll dp[MM]; pii p[MM];
int main(){
    n = re, memset(dp, 0x3f, sizeof dp), dp[0] = 0;
    for (int i = 0; i < n; i++) p[i] = {abs(re), abs(re)};
    sort(p, p + n);
    for (int i = 0; i < n; st[++t] = i++)
        while(t && p[i].second >= p[st[t]].second) t--;
    for (int i = 1; i <= t; i++)
        for (int j = 0; j < i; j++)
            dp[i] = min(dp[i], dp[j] + 1LL * p[st[i]].first * p[st[j + 1]].second);
    printf("%lld\n", 4 * dp[t]);
}
