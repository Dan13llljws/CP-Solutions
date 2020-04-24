#include <iostream>
#include <algorithm>
using namespace std;
int n, m, ans, psa[101][101];
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0, x, y; i < m; i++){
		scanf("%d%d", &x, &y);
		psa[x][y] = 1;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
	for (int i = 1; i <= m; i++){
		if (m % i) continue;
		int w = i, l = m / i;
		if (w > n || l > n) continue;
		for (int j = w; j <= n; j++)
			for (int k = l; k <= n; k++)
				ans = max(ans, psa[j][k] - psa[j - w][k] - psa[j][k - l] + psa[j - w][k - l]);
	}
	printf("%d", m - ans);
	return 0;
}
