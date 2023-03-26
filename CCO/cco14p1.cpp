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
int n, dp[2005][2005], cnt;
char grid[2005][2005];
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(n);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            sc(grid[i][j]);
        }
    }
    for (int i = n; i > 0; i--){
        for (int j = 1; j <= n; j++){
            if (grid[i][j] == '#'){
                dp[i][j] = min({dp[i + 1][j - 1], dp[i + 1][j], dp[i + 1][j + 1]}) + 1;
            }
            cnt += dp[i][j];
        }
    }
    pr(cnt);
    return 0;
}
