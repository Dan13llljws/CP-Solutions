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
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int , pii> piii;
typedef pair<ll, pll> plll;
ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}

int n, p1, p2, x, y, dp[200001][2];
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(n); p1 = 1, p2 = 1;
    for (int i = 1; i <= n; i++){
        sc(x, y);
        dp[i][0] = min(abs(y - p1) + dp[i - 1][0], abs(y - p2) + dp[i - 1][1]) + abs(y - x);
        dp[i][1] = min(abs(x - p1) + dp[i - 1][0], abs(x - p2) + dp[i - 1][1]) + abs(y - x);
        p1 = x; p2 = y;
    }
    pr(min(dp[n][0] + n - p1, dp[n][1] + n - p2) + n - 1);
    return 0;
}
