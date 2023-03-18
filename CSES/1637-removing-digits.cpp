#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> dp(n + 1, 1e9);
	dp[0] = 0;
	for (int i = 1; i <= n; i++){
		int t = i;
		while(t){
			dp[i] = min(dp[i], dp[i - t % 10] + 1);
			t /= 10;
		}
	}
	cout << dp[n] << '\n';
}


