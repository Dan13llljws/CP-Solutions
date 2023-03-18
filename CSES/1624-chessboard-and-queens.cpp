#include <bits/stdc++.h>
using namespace std;
int rec(vector<string> g, int k){
	if (k == 8) return 1;
	int ret = 0;
	for (int i = 0; i < 8; i++)	{
		if (g[i][k] == '.'){
			vector<string> ng = g;
			for (int dx = -1; dx <= 1; dx++)
				for (int dy = -1; dy <= 1; dy++){
					if (!dx && !dy) continue;
					int cx = i, cy = k;
					while(cx >= 0 && cx < 8 && cy >= 0 && cy < 8)
						ng[cx][cy] = '*', cx += dx, cy += dy;
				}
			ret += rec(ng, k + 1);
		}
	}
	return ret;
}
int main(){
	vector<string> g(8);
	for (int i = 0; i < 8; i++) cin >> g[i];
	cout << rec(g, 0) << '\n';
}
