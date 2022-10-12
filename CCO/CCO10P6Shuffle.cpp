#include <bits/stdc++.h>
using namespace std;
char t[100], s[27], ans[27]; int n; bool vis[27];
int main(){
	for (int i = 0; i < 27; i++){
		scanf("%c  ", &s[i]);
		if (s[i] == '_') s[i] = 'Z' + 1;
	} scanf("%d%s", &n, t);
	for (int i = 0; i < 27; i++){
		if (vis[i]) continue;
		vector<int> v;
		for (int j = i;; j = s[j] - 'A'){
			if (j == i && v.size()) break;
			v.push_back(j), vis[j] = 1;
		}
		for (int j = 0; j < (int)v.size(); j++)
			ans[v[j]] = v[(j + n) % v.size()] + 'A';
	}
	for (int i = 0; i < 27; i++) if (ans[i] == '[') ans[i] = '_';
	for (int i = 0; t[i]; i++) putchar(t[i] == '_' ? ans[26] : ans[t[i] - 'A']);
}
