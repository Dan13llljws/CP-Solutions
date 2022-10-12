#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
const int MM = 1e4 + 5;
int N, S, s[MM], f[MM], dp[MM], q[MM];	
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(N, S);
	for (int i = 1; i <= N; i++) sc(s[i], f[i]), s[i] += s[i - 1], f[i] += f[i - 1];
	int l = 1, r = 1; q[l] = N + 1;
	for (int i = 1; i <= N; i++){
		while(l < r && dp[q[l + 1]] - dp[q[l]] <= (s[i] + S) * (f[q[l + 1]] - f[q[l]])) l++;
		dp[i] = dp[q[l]] + (f[i] - f[q[l]]) * s[i] + S * (f[N] - f[q[l]]);
		while(l < r && (dp[q[r]] - dp[q[r - 1]]) * (f[i] - f[q[r]]) >= (dp[i] - dp[q[r]]) * (f[q[r]] - f[q[r - 1]])) r--;
		q[++r] = i;
	}
	pr(dp[N]);
	return 0;
}
