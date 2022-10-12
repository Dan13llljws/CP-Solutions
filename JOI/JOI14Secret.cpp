#include <bits/stdc++.h>
#include "secret.h"
using namespace std;
int n, g[1005][1005];
void build(int l, int r){
	if (r - l < 2) return;
	int mid = l + r >> 1;
	for (int i = mid - 1; i >= l; i--)
		g[i][mid] = Secret(g[i][i], g[i + 1][mid]);
	for (int i = mid + 2; i <= r; i++)
		g[mid + 1][i] = Secret(g[mid + 1][i - 1], g[i][i]);
	build(l, mid - 1), build(mid + 2, r);
}
void Init(int N, int A[]){
	memset(g, -1, sizeof g); n = N;
	for (int i = 0; i < n; i++) g[i][i] = A[i];
	build(0, n - 1);
}
int Query(int L, int R){
	if (g[L][R] != -1) return g[L][R];
	for (int i = L; i < R; i++)
		if (g[L][i] != -1 && g[i + 1][R] != -1) return Secret(g[L][i], g[i + 1][R]);
}
