#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> dp(1000*n+5);
	int sum = 0;
	dp[0] = 1;
	for (int i = 0; i < n; i++){
		int a;
		cin >> a;
		sum += a;
		for (int j = sum; j >= a; j--)
			dp[j] |= dp[j - a];
	}
	int cnt = 0;
	vector<int> ans;
	for (int i = 1; i <= sum; i++)
		if (dp[i]) cnt++, ans.push_back(i);
	cout << cnt << '\n';
	for (int x : ans) cout << x << ' ';
}



