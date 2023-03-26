#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define sz(x) (int)(x.size())
#define mp make_pair
#define pb push_back
const int MM = 1e5 + 5;
struct edge{int a, b, w;}edges[MM];
int N, M, K, dsu[MM], cnt;
vector<edge> must;
int Find(int x){
	return dsu[x] == x ? x : dsu[x] = Find(dsu[x]);
}
void unite(int x, int y){
	dsu[Find(x)]  = Find(y);
}
void init(){
	for (int i = 1; i <= N; i++) dsu[i] = i;
}
bool cmp1(edge a, edge b){return a.w < b.w;}
bool cmp2(edge a, edge b){return a.w > b.w;}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(N, M, K); init();
	for (int i = 0, a, b, w; i < M; i++){
		sc(a, b, w);
		edges[i] = {a, b, w};
	}
	sort(edges, edges + M, cmp2);
	for (int i = 0; i < M; i++){
		if (Find(edges[i].a) != Find(edges[i].b)){
			unite(edges[i].a, edges[i].b);
			if (!edges[i].w){
				cnt++;
				must.pb(edges[i]);
			}
		}
	}
	if (cnt > K) return 0 * printf("no solution");
	init();
	sort(edges, edges + M, cmp1);
	for (auto v : must) unite(v.a, v.b);
	for (int i = 0; i < M; i++){
		if (Find(edges[i].a) != Find(edges[i].b)){
			if (!edges[i].w){
				if (cnt < K){
					unite(edges[i].a, edges[i].b);
					must.pb(edges[i]);
					cnt++;
				}
			}
			else{
				unite(edges[i].a, edges[i].b);
				must.pb(edges[i]);
			}
		}
	}
	if (sz(must) < N - 1 || cnt < K) return 0 * printf("no solution");
	for (auto v : must) pr(v.a, sp, v.b, sp, v.w, nl);
	return 0;
}
	
