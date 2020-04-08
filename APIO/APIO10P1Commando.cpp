#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
const int mod = 1e9 + 7, base = 131;
typedef long long ll;
const int MM = 1e6 + 5;
ll N, a, b, c, s[MM], dp[MM];
int q[MM];
ll get(int j, int k){
	return dp[j] - dp[k] + a * (s[j] * s[j] - s[k] * s[k]) + b * (s[k] - s[j]);
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(N, a, b, c);
	for (int i = 1; i <= N; i++) sc(s[i]), s[i] += s[i - 1];
	int l = 1, r = 1;
	for (int i = 1; i <= N; i++){
		while(l < r && get(q[l + 1], q[l]) > 2 * a * s[i] * (s[q[l + 1]] - s[q[l]])) l++;
		dp[i] = dp[q[l]] + a * (s[i] - s[q[l]]) * (s[i] - s[q[l]]) + b * (s[i] - s[q[l]]) + c;
		while(l < r && get(q[r], q[r - 1]) * (s[i] - s[q[r]]) < get(i, q[r]) * (s[q[r]] - s[q[r - 1]])) r--;
		q[++r] = i;
	}
	pr(dp[N]);
	return 0;
}
/* math????
 * dp[i] = max{dp[j] + a*(s[i] - s[j])^2 + b*(s[i] - s[j]) + c}
 * dp[j] + a*(s[i] - s[j])^2 + b*(s[i] - s[j]) + c > dp[k] + a*(s[i] - s[k])^2 + b*(s[i] - s[k]) + c
 * dp[j] + a*s[i]^2 + 2*a*s[i]*s[j] + a*s[j]^2 + b*s[i] - b*s[j] + c > dp[k] + a*s[i]*2 + 2*a*s[i]*s[k] + a*s[k]^2 + b*s[i] - b*s[k] + c
 * dp[j] - 2*a*s[i]*s[j] + a*s[j]^2 - b*s[j] > dp[k] - 2*a*s[i]*s[k] + a*s[k]^2 - b*s[k] 
 * dp[j] - dp[k] + a*s[j]^2 - a*s[k]^2 + b*s[j] - b*s[k] > 2*a*s[i]*s[j] - 2*a*s[i]*s[k]
 * dp[j] - dp[k] + a*(s[j]^2 - s[k]^2) + b*(s[j] - s[k]) > 2*a*s[i]*(s[j] - s[k])
 */
