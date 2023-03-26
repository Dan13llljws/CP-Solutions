#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
typedef long long ll;
const int MM = 1e5 + 5;
int n, K, tmp, pre[205][MM], q[MM];
ll dp[MM][2], s[MM];
ll get(int j, int k, int l){
	return dp[k][j] - dp[l][j] - s[k] * s[k] + s[l] * s[l];
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(n, K);
	for (int i = 1; i <= n; i++) sc(s[i]), s[i] += s[i - 1];
	for (int k = 1; k <= K; k++, tmp ^= 1){
		int l = 1, r = 1; 
		for (int i = 1; i <= n; i++){
			while(l < r && get(tmp ^ 1, q[l + 1], q[l]) >= s[i] * (s[q[l]] - s[q[l + 1]])) l++;
			dp[i][tmp] = dp[q[l]][tmp ^ 1] + (s[i] - s[q[l]]) * s[q[l]];
			pre[k][i] = q[l];
			while(l < r && get(tmp ^ 1, q[r], q[r - 1]) * (s[q[r]] - s[i]) >= get(tmp ^ 1, i, q[r]) * (s[q[r - 1]] - s[q[r]])) r--;
			q[++r] = i;
		}
	}
	pr(dp[n][tmp ^ 1], nl);
	for (int x = pre[K][n]; x; x = pre[--K][x]) pr(x, sp);
	return 0;
}
/*
 * dp[i][j] = max{dp[k][j - 1] + (s[i] - s[k]) * s[k]}
 * dp[i][j] = max{dp[k][j - 1] + s[i] * s[k] - s[k]^2
 * dp[k][j - 1] + s[i] * s[k] - s[k]^2 > dp[l][j - 1] + s[i] * s[l] - s[l]^2
 * dp[k][j - 1] - dp[l][j - 1] - s[k]^2 + s[l]^2 > s[i] * (s[l] - s[k])
 */
