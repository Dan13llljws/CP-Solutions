#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define pb push_back
int n, m, c, dp[1005][1005], a[1005], ans;
vector<int> adj[1005]; 
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(n, m, c);
    for (int i = 1; i <= n; i++) sc(a[i]);
    for (int i = 0, a, b; i < m; i++){
        sc(a, b); adj[a].pb(b); 
    }
    ms(dp, -1); dp[0][1] = a[1];
    for (int i = 0; i <= 1001; i++){
        for (int j = 1; j <= n; j++){
            if (dp[i][j] != -1){
                for (int v : adj[j]){
                    dp[i + 1][v] = max(dp[i + 1][v], dp[i][j] + a[v]);
                }
            }
            if (j == 1) ans = max(ans, dp[i][j] - c * i * i);
        }
    }
    pr(ans);
    return 0;
}
