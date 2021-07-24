#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
int n, t, ans, st[MM]; pair<int,int> p[MM];
int main(){
	//freopen("mountains.in", "r", stdin); freopen("mountains.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int x, y; scanf("%d%d", &x, &y);
		p[i] = {x - y + 1, x + y - 1};
	}
	sort(p, p + n, [&](pair<int,int> a, pair<int,int> b){return a.second == b.second ? a.first > b.first : a.second < b.second;});
	for (int i = 0; i < n; i++){
		while(t && p[st[t]].first >= p[i].first) t--;
		st[++t] = i;
	}
	printf("%d\n", t);
}
	
	
