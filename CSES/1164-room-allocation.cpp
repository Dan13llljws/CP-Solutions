#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<array<int, 3>> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i][0] >> p[i][1], p[i][2] = i;
	sort(p.begin(), p.end(), [](auto a, auto b){
		return a[1] < b[1];
	});
	multiset<pair<int,int>> s;
	vector<int> ans(n);
	for (auto x : p){
		if (s.empty() || -x[0] >= (*s.rbegin()).first){
			s.insert({-x[1], s.size() + 1});
			ans[x[2]] = s.size();
		} else {
			auto it = s.upper_bound({-x[0], 1e9});
			s.insert({-x[1], (*it).second});
			ans[x[2]] = (*it).second;
			s.erase(it);
		}
	}
	cout << s.size() << '\n';
	for (int x : ans) cout << x << ' ';
}

