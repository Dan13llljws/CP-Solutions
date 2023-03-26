#include <bits/stdc++.h>
using namespace std;
int n, m, t[101], dp[101], pre[101]; string name[101], out;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> m >> n; memset(dp, 0x3f, sizeof dp); dp[0] = 0;
	for (int i = 1; i <= n; i++){
		cin >> name[i] >> t[i];
		int mx = 0;
		for (int j = i - 1; j >= max(0, i - m); j--){
			mx = max(mx, t[j + 1]);
			if (dp[j] + mx < dp[i]) dp[i] = dp[j] + mx, pre[i] = j;
		}
	}
	cout << "Total Time: " << dp[n];
	for (int x = n; x; x = pre[x]){
		for (int i = x; i > pre[x]; i--) out = name[i] + " " + out;
		out = "\n" + out;
	}
	cout << out;
}
	
	
