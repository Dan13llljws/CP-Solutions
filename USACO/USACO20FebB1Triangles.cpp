#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sp ' '
#define nl '\n'
#define setIO(x) freopen("(x).in", "r", stdin); freopen("(x).out", "w", stdout);
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define f first
#define s second
typedef pair<int, int> pii;
int n, ans;
pii c[101];
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(n);
	for (int i = 0; i < n; i++) sc(c[i].f, c[i].s);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (c[j].s == c[i].s && c[k].f == c[i].f)
					ans = max(ans, abs(c[j].f - c[i].f) * abs(c[k].s - c[i].s));
	pr(ans);
	return 0;
}

