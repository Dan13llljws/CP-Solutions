#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, MM = 2005;
int n, g[MM][MM], t[MM]; char c;
int main(){
	scanf("%d", &n); getchar(); iota(t + 1, t + 1 + n, 1);
	for (int i = 2; i <= n; i++, getchar())
		for (int j = 1; j < i; j++)
			g[i][j] = g[j][i] = getchar() == 'R';
	for (int i = 1; i <= n; i++){
		vector<int> r, b; swap(t[i], t[n]);
		if (i == n) swap(t[1], t[n]);
		r.push_back(t[1]), b.push_back(t[2]);
		for (int j = 3; j <= n; j++){
			int k = t[j];
			if (!r.size() || g[k][r.back()]) r.push_back(k);
			else if (!b.size() || !g[k][b.back()]) b.push_back(k);
			else {
				if (g[r.back()][b.back()]) r.push_back(b.back()), r.push_back(k), b.pop_back();
				else b.push_back(r.back()), b.push_back(k), r.pop_back();
			}
		} printf("%d\n", n);
		if (r.back() == i){
			for (int j = r.size() - 1; j >= 0; j--) printf("%d ", r[j]);
			for (int j = 0; j < (int)b.size(); j++) printf("%d ", b[j]);
		} else {
			for (int j = b.size() - 1; j >= 0; j--) printf("%d ", b[j]);
			for (int j = 0; j < (int)r.size(); j++) printf("%d ", r[j]);
		} puts("");
	}
}

