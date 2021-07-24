#include <bits/stdc++.h>
using namespace std;
const int MM = 1005;
int n, k, ans, psa[MM][MM];
int main(){
	//freopen("paintbarn.in", "r", stdin); freopen("paintbarn.out", "w", stdout);
	scanf("%d%d", &n, &k);
	while(n--){
		int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d); a++, b++, c++, d++;
		psa[a][b]++, psa[c][b]--, psa[a][d]--, psa[c][d]++;
	}
	for (int i = 1; i <= 1000; i++)
		for (int j = 1; j <= 1000; j++)
			ans += (psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1]) == k;
	printf("%d\n", ans);
}
