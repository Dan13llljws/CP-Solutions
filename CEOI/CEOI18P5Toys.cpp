#include <bits/stdc++.h>
using namespace std;
int n; vector<int> ans;
void rec(int x, int d, int sum){
	ans.push_back(sum + x - 1);
	for (int i = d; i * i <= x; i++)
		if (x % i == 0) rec(x / i, i, sum + i - 1);
}
int main(){
	scanf("%d", &n);
	rec(n, 2, 0);
	sort(ans.begin(), ans.end()); ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
	printf("%d\n", (int)ans.size());
	for (int x : ans) printf("%d ", x);
}
