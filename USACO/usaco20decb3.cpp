#include <bits/stdc++.h>
using namespace std;
int n, x[55], y[55], ans[55]; vector<int> xx, yy;
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		char c;
		scanf(" %c %d%d", &c, x + i, y + i);
		if (c == 'E') xx.push_back(i);
		else yy.push_back(i);
	}
	sort(xx.begin(), xx.end(), [](int a, int b){return y[a] < y[b];});
	sort(yy.begin(), yy.end(), [](int a, int b){return x[a] < x[b];});
	for (int i : xx)
		for (int j : yy){
			if (ans[i] || ans[j] || x[i] >= x[j] || y[i] <= y[j] || x[j] - x[i] == y[i] - y[j]) continue;
			if (x[j] - x[i] > y[i] - y[j]) ans[i] = x[j] - x[i];
			else ans[j] = y[i] - y[j];
		}
	for (int i = 0; i < n; i++)
		if (!ans[i]) puts("Infinity");
		else printf("%d\n", ans[i]);
}
