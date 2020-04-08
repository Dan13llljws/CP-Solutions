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
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 1e5 + 5, mod = 1e9 + 7, MS = 1e4;
struct point{int x, y; ll s[2];} v[MM];
int N; ll ans;
vector<pii> proc[2 * MS + 5];
void process(int t){
	for (int i = 0; i <= 2 * MS; i++){
		if (!sz(proc[i])) continue;
		sort(af(proc[i]));
		ll sum = 0; int n = sz(proc[i]);
		for (int j = 1; j < n; j++){
			v[proc[i][j].s].s[t] += (j * (proc[i][j].f - proc[i][0].f) - sum) % mod;
			sum += proc[i][j].f - proc[i][0].f;
		}
		sum = 0;
		for (int j = n - 2; j >= 0; j--){
			v[proc[i][j].s].s[t] += ((n - j - 1) * (proc[i][n - 1].f - proc[i][j].f) - sum) % mod;
			sum += proc[i][n - 1].f - proc[i][j].f;
		}
		proc[i].clear();
	}
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sc(N);
    for (int i = 0; i < N; i++) sc(v[i].x, v[i].y);
    for (int i = 0; i < N; i++) proc[v[i].x + MS].pb(mp(v[i].y + MS, i));
    process(0); 
    for (int i = 0; i < N; i++) proc[v[i].y + MS].pb(mp(v[i].x + MS, i));
    process(1);
    for (int i = 0; i < N; i++) ans = (ans + (v[i].s[0] * v[i].s[1]) % mod) % mod;
	pr(ans);
    return 0;
}
