#include <bits/stdc++.h>
using namespace std;
int n, k, ans; vector<int> vec, gap;
int main(){
	scanf("%d%d", &n, &k);
	for (int i = 0, x; i < n; i++) scanf("%d", &x), vec.push_back((x - 1) / 12);
	sort(vec.begin(), vec.end()); vec.resize(ans = n = unique(vec.begin(), vec.end()) - vec.begin());
	if (vec[0]) k--, gap.push_back(vec[0]);
	for (int i = 1; i < n; i++) gap.push_back(vec[i] - vec[i - 1] - 1);
	sort(gap.begin(), gap.end());
	for (int i = 0; i < n - k; i++) ans += gap[i];
	printf("%d\n", ans * 12);
}
