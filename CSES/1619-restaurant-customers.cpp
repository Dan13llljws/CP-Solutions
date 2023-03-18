#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int,int>> p;
	for (int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		p.push_back({a, 0}), p.push_back({b, 1});
	}
	sort(p.begin(), p.end());
	int cur = 0, ans = 0;
	for (auto x : p){
		if (x.second) cur--;
		else cur++;
		ans = max(ans, cur);
	}
	cout << ans << '\n';
}
