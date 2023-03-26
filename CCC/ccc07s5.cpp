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
const int MOD = 1e9 + 7, MAXX = 3e4 + 5;
int t, n, k, w, dp[501][MAXX], psa[MAXX];
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(t);
    while(t--){
        sc(n, k, w);
        for (int i = 1; i <= n; i++){
            sc(psa[i]); psa[i] += psa[i - 1];
        }
        for (int i = 1; i <= k; i++){
            for (int j = (i - 1) * w + 1; j <= n; j++){
                if (j <= w) dp[i][j] = psa[j];
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - w] + psa[j] - psa[j - w]);
            }
        }
        pr(dp[k][n], nl);
    }
    return 0;
}