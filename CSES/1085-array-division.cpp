#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	long long l = *max_element(a.begin(), a.end()), r = 1e15; 
	while(l < r){
		long long mid = (l + r) >> 1;
		long long cnt = 0, cur = 0;
		for (int x : a){
			if (cur + x <= mid) cur += x;
			else cur = x, cnt++;
		}
		if (cnt + 1 <= k) r = mid;
		else l = mid + 1;
	}
	cout << l << '\n';
}
