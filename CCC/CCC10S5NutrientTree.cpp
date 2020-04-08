#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
const int MM = 2501;
string str;
int X, pos, val[MM], dp[MM][MM], l[MM], r[MM];
void build(int i){
	while(str[pos] == ' ' || str[pos] == ')') pos++;
	if (str[pos] == '(') pos++, build(i * 2), build(i * 2 + 1);
	else while(str[pos] >= '0' && str[pos] <= '9') val[i] = val[i] * 10 + str[pos] - '0', pos++;
}
void dfs(int i){
	if (val[i] > 0){
		for (int j = 0; j <= X; j++) dp[i][j] = val[i] + j;
		return;
	}
	dfs(i * 2); dfs(i * 2 + 1);
	for (int j = 0; j <= X; j++){
		l[j] = 0;
		for (int k = 0; k <= j; k++) // left
			l[j] = max(l[j], min((1 + k) * (1 + k), dp[i * 2][j - k]));
	}
	for (int j = 0; j <= X; j++){
		r[j] = 0;
		for (int k = 0; k <= j; k++) // right
			r[j] = max(r[j], min((1 + k) * (1 + k), dp[i * 2 + 1][j - k]));
		for (int k = 0; k <= j; k++) // dp
			dp[i][j] = max(dp[i][j], l[k] + r[j - k]);
	}	
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	getline(cin, str); sc(X);
	build(1); dfs(1);
	pr(dp[1][X]);
	return 0;
}

