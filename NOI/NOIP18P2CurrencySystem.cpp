#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 25005;
int t, n, ans, a[101], dp[MM];
int main(){
    t = re;
    while(t--){
        n = re, ans = 0, memset(dp, 0, sizeof dp), dp[0] = 1;
        for (int i = 0; i < n; i++) a[i] = re;
        sort(a, a + n);
        for (int i = 0; i < n; i++){
            if (dp[a[i]]) continue;
            ans++;
            for (int j = a[i]; j < MM; j++)
                dp[j] |= dp[j - a[i]];
        } printf("%d\n", ans);
    }
}
