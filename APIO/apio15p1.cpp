#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 2005;
int n, A, B, dp1[MM]; ll ans, a[MM]; bitset<105> dp[105];
int main(){
    n = re, A = re, B = re, ans = (1LL << 41) - 1;
    for (int i = 1; i <= n; i++) a[i] = a[i - 1] + re;
    for (int i = 40; i >= 0; i--){
        ans ^= (1LL << i);
        if (A == 1){
            memset(dp1, 0x3f, sizeof dp1), dp1[0] = 0;
            for (int j = 1; j <= n; j++)
                for (int k = 0; k < j; k++)
                    if ((ans | (a[j] - a[k])) == ans) dp1[j] = min(dp1[j], dp1[k] + 1); 
            if (dp1[n] > B) ans |= (1LL << i); 
            continue;
        }
        for (int j = 1; j <= n; j++) dp[j].reset();
        dp[0][0] = 1;
        for (int j = 1; j <= n; j++)
            for (int k = 0; k < j; k++)
                if (((a[j] - a[k]) | ans) == ans) dp[j] |= dp[k] << 1;
        bool f = 0;
        for (int j = A; j <= B && !f; j++) f |= dp[n][j];
        if (!f) ans |= (1LL << i);

    } printf("%lld\n", ans);

}
