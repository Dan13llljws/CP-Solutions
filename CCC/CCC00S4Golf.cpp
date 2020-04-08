#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define INF 0x3f3f3f3f
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))
int d, t, a[40], dp[6000];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> d >> t;
    ms(dp, INF);
    for (int i = 0; i < t; i++) cin >> a[i];
    for (int i = 0; i < t; i++){
        dp[a[i]] = 1;
        for (int j = 0; j < d + 1; j++){
            dp[j + a[i]] = min(dp[j + a[i]], dp[j] + 1);
        }
    }
    if (dp[d] != INF) cout << "Roberta wins in " << dp[d] << " strokes.";
    else cout << "Roberta acknowledges defeat.";
    return 0;
}