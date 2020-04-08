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
const int MM = 1e6 + 5;
int N, pre[MM], maxd;
pii p[MM], bit[MM], ans;
void update(int pos, pii v){
	for (; pos <= maxd; pos += (pos & -pos))
		if (bit[pos].f < v.f) bit[pos] = v;
}
pii get(int pos){
	pii ret(0, -1);
	for (; pos > 0; pos -= (pos & -pos))
		if (bit[pos].f > ret.f) ret = bit[pos];
	return ret;
}
bool cmp(pii a, pii b){
	if (a.f == b.f) return a.s < b.s;
	return a.f > b.f;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(N); ms(pre, -1); ms(bit, -1);	
	for (int i = 0; i < N; i++) sc(p[i].f, p[i].s), maxd = max(maxd, p[i].s);
	sort(p, p + N, cmp);
	for (int i = 0; i < N; i++){
		pii m = get(p[i].s);
		pre[i] = m.s;
		if (ans.f < m.f + 1) ans = {m.f + 1, i};
		update(p[i].s, {m.f + 1, i});
	}
	pr(ans.f, nl);
	for (int x = ans.s; x != -1; x = pre[x])
		pr(p[x].f, sp, p[x].s, nl);
	return 0;
}

