#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<pair<int,int>> p(n);
	for (auto &x : p) cin >> x.second >> x.first;
	sort(p.begin(), p.end());
	multiset<int> s;
	int ans = 0;
	for (auto x : p){
		if ((int)s.size() == k && -x.second > *s.rbegin()) continue;
		if (!s.empty() && -x.second <= *s.rbegin()) s.erase(s.lower_bound(-x.second));
		s.insert(-x.first);
		ans++;
	}
	cout << ans << '\n';
}

