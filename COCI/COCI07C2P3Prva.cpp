#include <iostream>
using namespace std;
char str[21][21]; int n, m;
int main(){
	scanf("%d%d",&n, &m);
	for (int i = 0; i < n; i++) scanf("%s", str[i]);
	string ans = "{{{{{{", cur;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (str[i][j] == '#'){
				if (cur.size() > 1 && ans > cur) ans = cur;
				cur.clear();
			}
			else cur.push_back(str[i][j]);
		}
		if (cur.size() > 1 && ans > cur) ans = cur;
		cur.clear();
	}
	for (int j = 0; j < m; j++){
		for (int i = 0; i < n; i++){
			if (str[i][j] == '#'){
				if (cur.size() > 1 && ans > cur) ans = cur;
				cur.clear();
			}
			else cur.push_back(str[i][j]);
		}
		if (cur.size() > 1 && ans > cur) ans = cur;
		cur.clear();
	}
	cout << ans;
	return 0;
}
