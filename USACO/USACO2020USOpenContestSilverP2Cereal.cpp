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
int N, M, vis[MM], ans[MM], cnt;
pii cows[MM];
void change(int x, int pos){
	if (cows[x].f == pos){
		if (vis[cows[x].s]){
			if (vis[cows[x].s] > x){
				change(vis[cows[x].s], cows[x].s);
				vis[cows[x].s] = x;
			}
		}
		else cnt++, vis[cows[x].s] = x;
	}
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("cereal.in", "r", stdin); freopen("cereal.out", "w", stdout);
	sc(N, M);
	for (int i = 1; i <= N; i++) sc(cows[i].f, cows[i].s);
	for (int i = N; i; i--){
		if (vis[cows[i].f]) change(vis[cows[i].f], cows[i].f);
		else cnt++;
		vis[cows[i].f] = i;
		ans[i] = cnt;
	}
	for (int i = 1; i <= N; i++) pr(ans[i], nl);
	return 0;
}
