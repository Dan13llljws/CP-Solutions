#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 55;
int n, m, len[MM]; char s[MM]; ll v[MM]; set<ll> ed, vis; unordered_map<ll,int> d; priority_queue<pair<int,pair<ll,int>>> q;
int getl(ll x){return 64 - __builtin_clzll(x);}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++){
		scanf("%s", s); len[i] = strlen(s);
		for (int j = 0; j < len[i]; j++)
			v[i] |= 1LL * (s[j] - '0') << j;
		v[i] |= 1LL << len[i], ed.insert(v[i]), q.push({-len[i], {v[i], 0}}); v[i] &= (1LL << len[i]) - 1;
	}
	while(q.size()){
		ll src = q.top().second.first; int dis = -q.top().first, l = getl(src) - 1, t = q.top().second.second; q.pop();
		if (t && dis > d[src]) continue;
		if (ed.count(src) && t) return 0 * printf("%d\n", dis);
		src &= (1LL << l) - 1;
		for (int i = 0; i < n; i++){
			if (len[i] > l && (v[i] & src) == src){
				bool w = 1;
				for (int j = 0; j < l; j++) w &= (v[i] >> j & 1) == (src >> j & 1);
				if (!w) continue;
				ll u = (v[i] >> l) | (1LL << (len[i] - l));
				if (!d.count(u) || d[u] > dis + len[i] - l) d[u] = dis + len[i] - l, q.push({-dis - len[i] + l, {u, 1}});
			} else if (len[i] <= l && (v[i] & src) == v[i]){
				bool w = 1;
				for (int j = 0; j < len[i]; j++) w &= (v[i] >> j & 1) == (src >> j & 1);
				if (!w || len[i] == dis) continue;
				ll u = (src >> len[i]) | (1LL << (l - len[i]));
				if (!d.count(u) || d[u] > dis) d[u] = dis, q.push({-dis, {u, 1}});
			}
		}
	}
	puts("-1");
}
		
