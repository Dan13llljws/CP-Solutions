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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MM = 2e6 + 5, base = 131;
int N, ans; char str[MM];
ull p[MM];
map<ull, int> dp;	
int main(){ // PRO TIP NEVER USE SYNC_WITH_STDIO WITH SCANF THIS SHT TOOK ME HRS TO REALIZE
    //freopen("", "r", stdin); freopen("", "w", stdout);
    scanf("%d", &N); p[0] = 1;
    for (int i = 1; i < MM; i++) p[i] = p[i - 1] * base;
	for (int i = 0; i < N; i++){
		scanf("%s", str);
		int m = strlen(str);
		int cnt = 0; ull hl = 0, hr = 0;
		for (int j = 0; j < m; j++){
			hl = hl * base + int(str[j]);
			hr = hr + p[j] * int(str[m - j - 1]);
			if (hl == hr) cnt = max(cnt, dp[hl]);
		}
		dp[hl] = cnt + 1;
		ans = max(ans, cnt + 1);
	}
	printf("%d", ans);
    return 0;
}
