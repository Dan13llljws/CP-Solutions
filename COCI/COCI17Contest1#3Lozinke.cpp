#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
unordered_map<string, int> vis, cnt;
int n, ans;
int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		string str; cin >> str;
		if (vis.count(str)) ans += vis[str];
		unordered_set<string> gay;
		for (int j = 0; j < str.length(); j++)
			for (int k = 1; j + k <= str.length(); k++){
				string tmp = str.substr(j, k);
				if (gay.count(tmp)) continue;
				if (cnt.count(tmp)) ans += cnt[tmp];
				vis[tmp]++;
				gay.insert(tmp);
			}
		cnt[str]++;
	}
	cout << ans;
	return 0;
}
