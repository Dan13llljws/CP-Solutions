#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	int cnt = 0;
	vector<string> ans;
	do{
		ans.push_back(s), cnt++;
	}while(next_permutation(s.begin(), s.end()));
	cout << cnt << '\n';
	for (string str : ans) cout << str << '\n';
}
