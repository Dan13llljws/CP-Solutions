#include <bits/stdc++.h>
using namespace std;
typedef pair<int, bool> pib;
int L, N, pre, cnt, ans;
vector<pib> s;
int main(){
	scanf("%d%d", &L, &N);
	for (int i = 0; i < N; i++){
		int l, r; scanf("%d%d", &l, &r);
		s.emplace_back(l, 0); s.emplace_back(r, 1);
	}
	s.emplace_back(L, 0); 
	sort(s.begin(), s.end());
	for (pib l : s){
		if (l.second) cnt--, pre = l.first;
		else {
			if (!cnt) ans = max(ans, l.first - pre);
			cnt++;
		}
	}
	printf("%d", ans);
	return 0;
}
	
