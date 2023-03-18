#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> a(1 << n), vis(1 << n);
	vis[0] = 1;
	for (int i = 0, x = 0; i < (1 << n); i++){
		for (int j = n - 1; j >= 0; j--)
			cout << (x >> j & 1);
		cout << '\n';
		for (int j = 0; j < n; j++)
			if (!vis[x ^ (1 << j)]){
				vis[x = x ^ (1 << j)] = 1;
				break;
			}
	}
}
