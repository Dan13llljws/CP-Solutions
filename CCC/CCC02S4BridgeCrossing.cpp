#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define ms(x, y) memset(x, y, sizeof(x))
int n, q, dp[101], s[101], pre[101];
string name[101], out;
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(n, q); ms(dp, INF); dp[0] = 0;
    for (int i = 1; i <= q; i++){
        sc(name[i], s[i]);  
        int m = s[i];
        for (int j = i; j > i - n && j > 0; j--){
            m = max(m, s[j]);
            if (dp[i] > dp[j - 1] + m){
                dp[i] = dp[j - 1] + m;
                pre[i] = j - 1;
            }
        }
    }
    pr("Total Time: ", dp[q], nl);
    int i = q;
    while(i){
        int tmp = pre[i];
        while(i > tmp){
            out = name[i] + ' ' + out;
            i--;
        }
        if (tmp) out = nl + out;
    }
    pr(out);
    return 0;
}