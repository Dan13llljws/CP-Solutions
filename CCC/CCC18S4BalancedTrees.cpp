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
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MM = 32000;
int n, sq; ll lo[MM], hi[MM];
ll rec(int x){
	if (x == 1) return 1;
	ll &tot = x <= sq ? lo[x] : hi[n / x];
	if (tot) return tot;
	int k = x;
	while(k >= 2){
		int y = x / k;
		int nxt = x / (y + 1);
		tot += rec(y) * (k - nxt);
		k = nxt;
	}
	return tot;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("", "r", stdin); freopen("", "w", stdout);
	sc(n); sq = sqrt(n);
	pr(rec(n));
	return 0;
}

