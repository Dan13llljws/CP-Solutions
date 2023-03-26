#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
typedef long long ll;
int n; ll a[1001], b[1001], dp[1001][1001];
string s, t;
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(n, s);  for (int i = 0; i < n; i++) sc(a[i]);
    sc(t); for (int i = 0; i < n; i++) sc(b[i]);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if ((s[i - 1] - t[j - 1]) * (a[i - 1] - b[j - 1]) > 0){
                dp[i][j] = dp[i - 1][j - 1] + a[i - 1] + b[j - 1];
            }
            dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i][j]});
        }
    }
    pr(dp[n][n]);
    return 0;
}
