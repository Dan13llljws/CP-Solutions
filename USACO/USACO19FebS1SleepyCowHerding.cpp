#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
int n, mx, mn = 1e9, a[MM];
int main(){
	//freopen("herding.in", "r", stdin); freopen("herding.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	sort(a, a + n);
	mx = max(a[n - 1] - a[1], a[n - 2] - a[0]) - n + 2;
	if ((a[n - 2] - a[0] == n - 2 && a[n - 1] - a[n - 2] > 2) || (a[n - 1] - a[1] == n - 2 && a[1] - a[0] > 2)) mn = 2;
	else {
		for (int i = 0, j = 0; i < n; i++){
			while(a[i] - a[j] >= n) j++;
			mn = min(mn, n - (i - j + 1));
		}
	}
	printf("%d\n%d\n", mn, mx);
}
