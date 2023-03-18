#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string a, b;
	cin >> a >> b;
	vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));
	for (int i = 0; i <= (int)a.size(); i++)
		for (int j = 0; j <= (int)b.size(); j++){
			if (!i) dp[i][j] = j;
			else if (!j) dp[i][j] = i;
			else dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (a[i - 1] != b[j - 1])});
		}
	cout << dp[a.size()][b.size()] << '\n';
}



