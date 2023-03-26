#include <bits/stdc++.h>
using namespace std;
int r, c, a[30]; unordered_set<int> ans;
int main(){
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++)
		for (int j = 0, x; j < c; j++) scanf("%d", &x), a[i] |= (x << j);
	for (int i = r - 1; i >= 0; i--)
		a[i] ^= a[i + 1], ans.insert(a[i]);
	printf("%d", ans.size());
}
		
