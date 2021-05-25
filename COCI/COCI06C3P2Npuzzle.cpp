#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;
string s[4] = {"ABCD", "EFGH", "IJKL", "MNO."};
unordered_map<char, pair<int, int>> pos;
int ans;
int main(){
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			pos[s[i][j]] = {i, j};
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++){
			char c; cin >> c;
			if (c == '.') continue;	
			ans += abs(i - pos[c].first) + abs(j - pos[c].second);
		}
	cout << ans;
	return 0;	
}
