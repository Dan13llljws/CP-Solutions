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
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MM = 3e4 + 5;
int N, M, st, ed, dist[MM];
unordered_set<int> s[MM];
priority_queue<pii, vector<pii>, greater<pii>> q;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(N, M);
	for (int i = 0, a, b; i < M; i++){
		sc(a, b); 
		if (i == 0) st = a;
		if (i == 1) ed = a;
		s[a].insert(b);
	}
	ms(dist, INF); dist[st] = 0;
	q.push({0, st});
	while(sz(q)){
		int p = q.top().s, d = q.top().f; q.pop();
		if (p == ed){pr(d); return 0;}
		if (d > dist[p]) continue;
		for (auto &i : s[p]){
			for (int j = 1; p + i * j < N; j++){
				if (dist[p + i * j] > dist[p] + j){
					dist[p + i * j] = dist[p] + j;
					q.push({dist[p + i * j], p + i * j});
				}
				if (s[p + i * j].count(i)) break;
			}
			for (int j = 1; p - i * j >= 0; j++){
				if (dist[p - i * j] > dist[p] + j){
					dist[p - i * j] = dist[p] + j;
					q.push({dist[p - i * j], p - i * j});
				}
				if (s[p - i * j].count(i)) break;
			}
		}
	}
	pr(-1);
	return 0;
}
