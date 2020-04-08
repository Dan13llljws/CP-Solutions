#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define f first
#define s second
const int mod = 1e9 + 7, base = 131;
typedef long long ll;
typedef pair<ll, ll> pii;
const int MM = 1e5 + 5;
int N, M; ll ed;
pii intervals[MM];
bool check(ll x){
	ll cur = 0, pos = intervals[0].f;
	for (int i = 0; i < N; i++){
		if (pos > ed) return 0;
		pos += x;
		while(pos > intervals[cur].s && cur < M) cur++;
		if (pos < intervals[cur].f) pos = intervals[cur].f;
	}
	return 1;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("socdist.in", "r", stdin); freopen("socdist.out", "w", stdout);
	sc(N, M);
	for (int i = 0; i < M; i++) sc(intervals[i].f, intervals[i].s);
	sort(intervals, intervals + M);
	ed = intervals[M - 1].s;
	ll l = 1, r = 1e18;
	while(l < r){
		ll mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	pr(l);
	return 0;
}


