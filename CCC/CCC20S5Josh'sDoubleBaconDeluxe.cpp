#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
const int MM = 1e6 + 5;
int n, a[MM], last[MM / 2];
double sum, dp[MM], ans; // if coach gets his burge, what is the p that Josh still gets his own
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
	sc(n);
	for (int i = 1; i <= n; i++) sc(a[i]), last[a[i]] = i;
	sum = dp[n] = (a[1] == a[n] ? 1 : 0); 
	for (int i = n - 1; i; i--){
		if (a[i] == a[1]) dp[i] = 1; // if choose his own it's always possible
		else if (i == last[a[i]]) dp[i] = (sum + 1) / (n - i + 1); // he's the new coach
		else dp[i] = dp[last[a[i]]]; // will choose his own still 
		sum += dp[i];
	}
	printf("%.8f", sum / n);
    return 0;
}
