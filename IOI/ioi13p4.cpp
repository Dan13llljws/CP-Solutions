#include <stdio.h>
const int MM = 5005;
int s[MM], d[MM], done[MM], cur, cst;
void dfs(int l, int r){
	if (l == r){
		done[l] = 1, d[l] = cur;
		if (cst) s[l] ^= 1;
		return;
	} int mid = (l + r) >> 1;
	for (int i = l; i <= mid; i++) if (!done[i]) s[i] ^= 1;
	if ((tryCombination(s) == cur) != cst) cst ^= 1, dfs(l, mid);
	else dfs(mid + 1, r);
}
void exploreCave(int N){
	for (int i = 0; i < N; i++)
		cur = i, cst = tryCombination(s) == cur, dfs(0, N - 1);
	answer(s, d);
}
