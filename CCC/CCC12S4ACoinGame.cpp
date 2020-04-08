#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
typedef long long ll;
int n; ll mask, fnl;
unordered_map<ll, ll> dist;
unordered_map<ll, bool> vis;
int get_top(ll state, int pos){
	for (int i = pos * 8; i < pos * 8 + 8; i++)
		if (state >> i & 1) return i - pos * 8;
	return 8;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while(sc(n), n != 0){
		fnl = mask = 0; vis.clear(); dist.clear();
		for (int i = 0, a; i < n; i++){
			sc(a);
			mask |= 1LL << (8 * i + a - 1);
			fnl |= 1LL << (8 * i + i);
		}
		queue<ll> q;  q.push(mask);
		vis[mask] = 1; dist[mask] = 0;
		while(!q.empty()){
			ll state = q.front(), d = dist[state]; q.pop();
			if (vis[fnl]) break;
			for (int i = 0; i < n; i++){
				int pos = get_top(state, i);
				if (pos == 8) continue;
				ll trans = state ^ (1LL << (8 * i + pos));
				if (i){
					int tmp = get_top(state, i - 1);
					ll new_pos = trans | (1LL << (8 * (i - 1) + pos));
					if (tmp > pos && !vis[new_pos]){
						vis[new_pos] = 1;
						dist[new_pos] = d + 1;
						q.push(new_pos);
					}
				}
				if (i < n - 1){
					int tmp = get_top(state, i + 1);;
					ll new_pos = trans | (1LL << (8 * (i + 1) + pos));
					if (tmp > pos && !vis[new_pos]){
						vis[new_pos] = 1;
						dist[new_pos] = d + 1;
						q.push(new_pos);
					}
				}
			}
		}
		if (vis[fnl]) pr(dist[fnl], nl);
		else pr("IMPOSSIBLE\n");
	}
	return 0;
}
