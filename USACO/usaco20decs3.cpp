#include <bits/stdc++.h>
using namespace std;
int n, ans[1005], x[1005], y[1005]; bool vis[1005]; vector<int> xx, yy;
int main(){
	scanf("%d", &n); getchar();
	for (int i = 1; i <= n; i++, getchar()){
		if (getchar() == 'E') yy.push_back(i);
		else xx.push_back(i);
		scanf("%d%d", x + i, y + i);
	}
	sort(xx.begin(), xx.end(), [](int a, int b){return x[a] < x[b];});
	sort(yy.begin(), yy.end(), [](int a, int b){return y[a] < y[b];});
	for (int i : xx)
		for (int j : yy){
			if (vis[i] || vis[j] || x[i] < x[j] || y[i] > y[j]) continue;
			if (x[i] - x[j] < y[j] - y[i]) vis[i] = 1, ans[j] += ans[i] + 1;
			else if (x[i] - x[j] > y[j] - y[i]) vis[j] = 1 , ans[i] += ans[j] + 1;
		}
	for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
}
