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
#define lsb(x) (x & -x)
const int mod = 1e9 + 7, base = 131;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MM = 1030;
int N, bit[MM][MM];
void update(int x, int y, int v){
	for (int i = x; i <= N; i += lsb(i))
		for (int j = y; j <= N; j += lsb(j))
			bit[i][j] += v;
}
int sum(int x, int y){
	int ret = 0;
	for (int i = x; i > 0; i -= lsb(i))
		for (int j = y; j > 0; j -= lsb(j))
			ret += bit[i][j];
	return ret;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while(1){
		int cmd; sc(cmd);
		if (cmd == 0) sc(N);
		if (cmd == 1){
			int x, y, v; sc(x, y, v);
			x++, y++;
			update(x, y, v);
		}
		if (cmd == 2){
			int l, b, r, t; sc(l, b, r, t); r++, t++;
			pr(sum(r, t) - sum(r, b) - sum(l, t) + sum(l, b), nl);
		}
		if (cmd == 3) break;
	}
	return 0;
}

