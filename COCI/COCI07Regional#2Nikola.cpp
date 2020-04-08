#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
int n, dp[1005][1005], c[1005], ans = INF;
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(n); ms(dp, INF);
    for (int i = 1; i <= n; i++) sc(c[i]);
    dp[0][1] = 0;
    for (int i = 0; i <= n; i++){
        for (int j = n; j > 0; j--){
            if (dp[i][j] == INF) continue;
            if (j - i) dp[i][j - i] = min(dp[i][j - i], dp[i][j] + c[j - i]);
            if (j + i + 1 <= n && i + 1 <= n) dp[i + 1][j + i + 1] = min(dp[i + 1][j + i + 1], dp[i][j] + c[j + i + 1]);
        }
    }
    for (int i = 1; i <= n; i++){
        ans = min(ans, dp[i][n]);
    }
    pr(ans);
    return 0;
}