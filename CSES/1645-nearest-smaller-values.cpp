#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = i - 1;
		while(~b[i] && a[i] <= a[b[i]]) b[i] = b[b[i]];
		cout << b[i] + 1 << ' ';
	}
}

