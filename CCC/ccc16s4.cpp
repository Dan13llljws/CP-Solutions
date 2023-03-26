#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
typedef long long ll;
const int MM = 4e2 + 5;
ll n, dp[MM][MM], ans, psa[MM];
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("", "r", stdin); freopen("", "w", stdout);
	sc(n); // learned this way from bruce cuz my old way took f**king 19 seconds
	for (int i = 1; i <= n; i++){ // but it still passed
		sc(dp[i][i]);
		ans = max(ans, dp[i][i]);
		psa[i] = dp[i][i] + psa[i - 1];
	}
	for (int len = 2; len <= n; len++){
		for (int i = 1; i <= n - len + 1; i++){
			int l = i, r = l + len - 1;
			for (int j = l, k = r; j < k;){
				if (dp[l][j] && dp[k][r] && dp[l][j] == dp[k][r]){
					if (j + 1 == k) dp[l][r] = max(dp[l][r], dp[l][j] + dp[k][r]);
					else if (dp[j + 1][k - 1]) dp[l][r] = max(dp[l][r], dp[l][j] + dp[j + 1][k - 1] + dp[k][r]);
				}
				if (psa[j] - psa[l - 1] == psa[r] - psa[k - 1]) j++, k--;
				else if (psa[j] - psa[l - 1] > psa[r] - psa[k - 1]) k--;
				else j++;
			}
			ans = max(ans, dp[l][r]);
		}
	}
	pr(ans);
	return 0;
}

