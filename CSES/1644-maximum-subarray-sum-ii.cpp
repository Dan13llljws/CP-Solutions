#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	vector<long long> x(n + 1), sum(n + 1);
	deque<int> q;
	long long ans = -1e18;
	q.push_back(0);
	for (int i = 1; i <= n; i++){
		cin >> x[i];
		sum[i] = sum[i - 1] + x[i];
		while(!q.empty() && q.front() < i - b) q.pop_front();
		if (i < a) continue;
		ans = max(ans, sum[i] - sum[q.front()]);
		while(!q.empty() && sum[q.back()] >= sum[i - a + 1]) q.pop_back();
		q.push_back(i - a + 1);
	}
	cout << ans << '\n';
}	

