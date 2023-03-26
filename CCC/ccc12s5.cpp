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
const int MOD = 1e9 + 7;
const int MAXX = 1e5;
int r, c, t, dp[30][30];
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(r, c, t); dp[1][1] = 1;
    for (int i = 0, x, y; i < t; i++){
        sc(x, y); dp[x][y] = -1;
    }
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            if (dp[i][j] == -1) continue;
            if (dp[i + 1][j] != -1) dp[i + 1][j]  += dp[i][j];
            if (dp[i][j + 1] != -1) dp[i][j + 1] += dp[i][j];
        }
    }
    pr(dp[r][c]);
    return 0;
}
