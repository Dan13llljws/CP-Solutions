#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define sqr(x) (x * x)
#define lsb(x) (x & -x)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
const int mod = 1e9 + 7, base = 131;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MM = 15e4 + 5;
int n, ans = INF, a[3][MM], dp[MM], ord[3] = {0, 1, 2};
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("", "r", stdin); freopen("", "w", stdout);
	sc(n);
	for (int i = 0; i < 3; i++)
		for (int j = 1; j <= n; j++) sc(a[i][j]);
	do{
		ms(dp, INF); dp[0] = 0;
		for (int i = 1; i <= n - 2; i++)
			dp[i] = min(dp[i], dp[i - 1] + a[ord[0]][i]);
		for (int i = 2; i <= n - 1; i++)
			dp[i] = min(dp[i], dp[i - 1] + a[ord[1]][i]);
		for (int i = 3; i <= n; i++)
			dp[i] = min(dp[i], dp[i - 1] + a[ord[2]][i]);
		ans = min(ans, dp[n]);
		
	}while(next_permutation(ord, ord + 3));
	pr(ans);
	return 0;
}

