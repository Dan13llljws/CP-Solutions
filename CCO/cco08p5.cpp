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
const int MOD = 1e9 + 7, MAXX = 1e7 + 5;
int n, ans = INF, sum, k, c, freq[MAXX]; bool dp[MAXX];
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(n); dp[0] = 1;
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        sc(k, c); sum += k * c;
        for(int j = sum; j > -1; j--){
            if(!dp[j]) continue;
            for(int a = j + c; a <= min(sum, j + k * c); a += c){
                if(dp[a]) break;
                dp[a] = 1;
            }
        }
    }
    // for (int i = 0; i < n; i++){
    //     sc(k, c); sum += k * c; ms(freq, 0);
    //     for (int j = c; j <= sum; j++){
    //         if (dp[j - c] && freq[j - c] < k && !dp[j]){
    //             dp[j] = 1; freq[j] = freq[j - c] + 1;
    //         }
    //     }
    // }
    ans = sum / 2;
    while(!dp[ans]) ans--;
    pr(sum - ans * 2);
    return 0;
}