#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<int> ans = {0};
	for (int i = 1; i < n; i++){
		vector<int> f(n);
		for (int j = 0; j < i; j++){
			int x; cin >> x;
			if (j < (i + 1) / 2) f[x] = 1;
		}
		if (f[ans[0]]) ans.insert(ans.begin(), i);
		else if (f[ans.back()]) ans.push_back(i);
		else {
			for (int j = 1; j < i; j++)
				if (f[ans[j - 1]] & f[ans[j]]){
					ans.insert(ans.begin() + j, i);
					break;
				}
		}
	}
	for (int x : ans) cout << x << ' ';
	cout << '\n';
}
