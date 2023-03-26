#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
int n, k, d[2*MM]; pair<int,int> p[2*MM]; multiset<pair<int,int>,greater<pair<int,int>>> s[2]; queue<int> q;
int main(){
	//freopen("piepie.in", "r", stdin); freopen("piepie.out", "w", stdout);
	scanf("%d%d", &n, &k); memset(d, 0x3f, sizeof d);
	for (int i = 0; i < 2 * n; i++){
		scanf("%d%d", &p[i].first, &p[i].second);
		if (i < n) swap(p[i].first, p[i].second);
		if (!p[i].first) d[i] = 1, q.push(i);
		else s[i >= n].insert({p[i].first, i});
	}
	while(q.size()){
		int src = q.front(); q.pop();
		auto it = s[src < n].lower_bound({p[src].second, 1000000000});
		while(it != s[src < n].end() && (*it).first >= p[src].second - k)
			d[(*it).second] = d[src] + 1, q.push((*it).second), it = s[src < n].erase(it);
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", d[i] == 0x3f3f3f3f ? -1 : d[i]);
}
		
	
