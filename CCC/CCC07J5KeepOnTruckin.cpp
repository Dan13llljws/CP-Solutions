#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define INF 0x3f3f3f3f
#define nl '\n'
#define For(i, a, b) for(int i=a; i<b; i++)
#define FOR(i, a) For(i, 0, a)
#define Forr(i, a, b) for(int i=a-1; i>=b; i--)
#define FORR(i, a) Forr(i, a, 0);
typedef long long ll;
ll A, B, n, a[40], dp[40];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    a[0] = 0; a[1] = 990; a[2] = 1010; a[3] = 1970; a[4] = 2030;
    a[5] = 2940; a[6] = 3060; a[7] = 3930; a[8] = 4060; a[9] = 4970;
    a[10] = 5030; a[11] = 5990; a[12] = 6010; a[13] = 7000;
    cin >> A >> B >> n; 
    dp[0] = 1;
    FOR(i, n) cin >> a[i + 14];
    sort(a, a + n + 14);
    FOR(i, n + 13){
        For(j, i + 1, n + 14){
            if (a[j] - a[i] >= A && a[j] - a[i] <= B) dp[j] += dp[i] ;
        }
    }
    cout << dp[n + 13] << nl;
    return 0;
}