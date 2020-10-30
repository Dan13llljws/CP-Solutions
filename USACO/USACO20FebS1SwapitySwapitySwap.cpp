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
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
int n, k, m, a[100010]; bool vis[100010];
pii seq[101];
int next(int x){
	for (int i = 0; i < m; i++)
		if (x >= seq[i].f && x <= seq[i].s) x = seq[i].s + seq[i].f - x;
	return x;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("swap.in", "r", stdin); freopen("swap.out", "w", stdout);
    sc(n, m, k);
    for (int i = 0; i < m; i++) sc(seq[i].f, seq[i].s);
    for (int i = 1; i <= n; i++){
		if (vis[i]) continue;
		vector<int> cyc; cyc.pb(i);
		int nxt = next(i); cyc.pb(nxt);
		while(nxt != i){
			nxt = next(nxt);
			cyc.pb(nxt);
		}
		cyc.pop_back();
		int g = k % sz(cyc);
		for (int j = 0; j < sz(cyc); j++){
			vis[cyc[j]] = 1;
			a[cyc[(j + g) % sz(cyc)]] = cyc[j];
		}
	}
	for (int i = 1; i <= n; i++) pr(a[i], nl);
    return 0;
}
