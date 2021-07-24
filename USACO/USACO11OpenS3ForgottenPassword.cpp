#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1005;
int n, m; string s, dp[MM], t[MM];
int main(){
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) cin >> t[i];
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < m; j++){
            int len = t[j].size(), f = 1;
            if (i < len || (i > len && !dp[i - len].size())) continue;
            for (int k = 0; k < len; k++)
                f &= s[i - len + k] == '?' || t[j][k] == s[i - len + k];
            if (f && (!dp[i].size() || dp[i] > dp[i - len] + t[j])) dp[i] = dp[i - len] + t[j];
        }
    } cout << dp[n];
}
