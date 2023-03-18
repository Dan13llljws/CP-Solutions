#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int,int>> p(n);
	for (auto &x : p) cin >> x.first >> x.second;
	sort(p.begin(), p.end());
	long long sum = 0, ans = 0;
	for (auto x : p){
		sum += x.first;
		ans += x.second - sum;
	}
	cout << ans << '\n';
}
