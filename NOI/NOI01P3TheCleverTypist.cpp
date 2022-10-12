#include <bits/stdc++.h>
using namespace std;
int a, b, d[1000000][6], p[6]; queue<pair<int,int>> q;
int main(){
	scanf("%d%d", &a, &b); memset(d, 0x3f, sizeof d);
	p[0] = 1, d[a][5] = 0, q.push({a, 5});
	for (int i = 1; i < 6; i++) p[i] = p[i - 1] * 10;
	while(!q.empty()){
		int src = q.front().first, i = q.front().second; q.pop();
		if (src == b) return 0 * printf("%d\n", d[src][i]);
		int dig = src / p[i] % 10, nd = src + p[i];
		if (dig < 9 && d[nd][i] > d[src][i] + 1) d[nd][i] = d[src][i] + 1, q.push({nd, i});
		nd = src - p[i];
		if (dig > 0 && d[nd][i] > d[src][i] + 1) d[nd][i] = d[src][i] + 1, q.push({nd, i});
		if (i < 5 && d[src][i + 1] > d[src][i] + 1) d[src][i + 1] = d[src][i] + 1, q.push({src, i + 1});
		if (i > 0 && d[src][i - 1] > d[src][i] + 1) d[src][i - 1] = d[src][i] + 1, q.push({src, i - 1});
		nd = src + (dig - src % 10) + (src % 10 - dig) * p[i];
		if (d[nd][i] > d[src][i] + 1) d[nd][i] = d[src][i] + 1, q.push({nd, i});
		nd = src + (dig - src / p[5]) * p[5] + (src / p[5] - dig) * p[i];
		if (d[nd][i] > d[src][i] + 1) d[nd][i] = d[src][i] + 1, q.push({nd, i});
	}
}

