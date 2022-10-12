#include <bits/stdc++.h>
using namespace std;
int n, k, ans, a[100], b[100], c[9];
int main(){
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) scanf("%d%d", a + i, b + i);
	for (int i = 0; i < n; i++) c[i] = i + 1;
	do {
		bool flag = 1;
		for (int i = 0; i < k; i++){
			bool va = 0;
			for (int j = 0; j < n; j++){
				if (c[j] == b[i] && !va){flag = 0; break;}
				if (c[j] == a[i]) va = 1;
			}
			if (!flag) break;
		}
		ans += flag;
	} while(next_permutation(c, c + n));
	printf("%d\n", ans);
}
