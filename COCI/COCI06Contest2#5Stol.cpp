#include <bits/stdc++.h>
using namespace std;
int R, C, ans, psa[405][405]; char g[405][405];
int main(){
	scanf("%d%d", &R, &C);
	for (int i = 1; i <= R; i++){
		scanf("%s", g[i] + 1);
		for (int j = 1; j <= C; j++)
			psa[i][j] += psa[i][j - 1] + (g[i][j] == 'X');
	}
	for (int l = 1; l <= C; l++){
		for (int r = l; r <= C; r++){
			int len = 0, maxl = 0;
			for (int i = 1; i <= R; i++){
				if (!(psa[i][r] - psa[i][l - 1])) len++, maxl = max(maxl, len);
				else len = 0;
			}
			if (maxl) ans = max(ans, 2 * (maxl + r - l + 1));
		}
	}
	printf("%d", ans - 1);
}
