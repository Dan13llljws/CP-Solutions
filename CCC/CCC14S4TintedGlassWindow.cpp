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
#define af(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MM = 1010;
struct glass{ll x1, y1, x2, y2, tint;}g[MM];
int n; ll t, psa[2 * MM][2 * MM], ans;
set<ll> xs, ys; vector<ll> xx, yy;
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(n, t); xs.insert(-1); ys.insert(-1);
    for (int i = 0, a, b, c, d, w; i < n; i++){
		sc(a, b, c, d, w);
		xs.insert(a); xs.insert(c);
		ys.insert(b); ys.insert(d);
		g[i] = {a, b, c, d, w};
	}
	xx = vector<ll>(af(xs)); yy = vector<ll>(af(ys));
	for (int i = 0; i < n; i++){
		int a = lb(af(xx), g[i].x1) - xx.begin(), b = lb(af(yy), g[i].y1) - yy.begin();
		int c = lb(af(xx), g[i].x2) - xx.begin(), d = lb(af(yy), g[i].y2) - yy.begin();
		int w = g[i].tint;
		psa[a][b] += w, psa[a][d] -= w, psa[c][b] -= w, psa[c][d] += w;
	}
	xx = vector<ll>(af(xs)); yy = vector<ll>(af(ys));
	for (int i = 1; i <= 2 * n; i++){
		for (int j = 1; j < 2 * n; j++){
			psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
			if (psa[i][j] >= t) ans += (xx[i + 1] - xx[i]) * (yy[j + 1] - yy[j]);
		}
	}
	pr(ans);
    return 0;
}

