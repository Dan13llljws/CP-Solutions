#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
const int mod = 1e9 + 7, base = 131;
typedef long long ll;
const int MM = 1e5 + 5;
struct edge{int a, b, w, t;};
int N, M, P, Q, dsu[2][MM]; ll tot, W;
vector<edge> edges;
bool cmp(edge a, edge b){return a.w < b.w;}
int Find(int x, int t){
	return dsu[t][x] == x ? x : dsu[t][x] = Find(dsu[t][x], t);
}
void unite(int x, int y, int t){
	dsu[t][Find(x, t)] = Find(y, t);
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(N, M, P, Q);
	for (int i = 1; i <= N; i++) dsu[0][i] = i; // planet(0)
	for (int i = 1; i <= M; i++) dsu[1][i] = i; // city(1)
	for (int i = 0, a, b, w; i < P; i++){
		sc(a, b, w); edges.pb({a, b, w, 1}); // 1 is flight b/c connects cities(1)
		tot += 1LL * w * N;
	}
	for (int i = 0, a, b, w; i < Q; i++){
		sc(a, b, w); edges.pb({a, b, w, 0}); // 0 is portal b/c connects planets(0)
		tot += 1LL * w * M;
	}
	sort(af(edges), cmp);
	for (int i = 0; i < sz(edges); i++){
		int t = edges[i].t;
		if (edges[i].t == 1){ // flight
			if (Find(edges[i].a, t) != Find(edges[i].b, t)){
				W += 1LL * edges[i].w * N; 
				unite(edges[i].a, edges[i].b, t);
				M--; // one less city
			}
		}
		else { // portal
			if (Find(edges[i].a, t) != Find(edges[i].b, t)){
				W += 1LL * edges[i].w * M; 
				unite(edges[i].a, edges[i].b, t);
				N--; // one less planet
			}
		}
	}
	pr(tot - W);
	return 0;
}

