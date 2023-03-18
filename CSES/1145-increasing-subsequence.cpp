#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> dp;
	while(n--){
		int a;
		cin >> a;
		if (dp.empty() || a > dp.back()) dp.push_back(a);
		else dp[lower_bound(dp.begin(), dp.end(), a) - dp.begin()] = a;
	}
	cout << dp.size() << '\n';
}


