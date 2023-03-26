#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define f first
#define s second
typedef pair<int, int> pii;
const int MM = 1e5 + 5;
int N, minp[MM], maxs[MM], ans;
pii p[MM];
bool cmp(pii a, pii b){
	if (a.f == b.f) return a.s < b.s;
	return a.f < b.f;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("moop.in", "r", stdin); freopen("moop.out", "w", stdout);
	sc(N);
	for (int i = 0; i < N; i++) sc(p[i].f, p[i].s);
	sort(p, p + N, cmp);
	minp[0] = p[0].s, maxs[N - 1] = p[N - 1].s;
	for (int i = 1; i < N; i++)
		minp[i] = min(minp[i - 1], p[i].s);
	for (int i = N - 2; i >= 0; i--)
		maxs[i] = max(maxs[i + 1], p[i].s);
	for (int i = 0; i < N; i++)
		if (minp[i] > maxs[i + 1]) ans++;
	pr(ans + 1, nl);
	return 0;
}
