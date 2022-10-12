#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
int n, dp[2][5005];
char s[100005];
int main(){
	scanf("%d %s", &n, s + 1);
	int cur = 0, nxt = 1;
	for (int i = 1; i <= n; i++){
		for (int j = n; j; j--){
			if (s[i] == s[j]) dp[nxt][j] = dp[cur][j + 1] + 1;
			else dp[nxt][j] = max(dp[nxt][j + 1], dp[cur][j]);
		}
		cur ^= 1, nxt ^= 1;
	}
	pr(n - dp[cur][1]);
	return 0;
}

