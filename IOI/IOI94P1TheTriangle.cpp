#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
#define flood(x) ms(x, 0x3f)
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
const int MOD = 1e9 + 7, MM = 105;
int n, dp[MM][MM], ans;
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(n);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            sc(dp[i][j]);
            dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }
    for (int i = 1; i <= n; i++) ans = max(ans, dp[n][i]);  
    pr(ans);
    return 0;
}
