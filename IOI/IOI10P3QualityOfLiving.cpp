#include <bits/stdc++.h>
using namespace std;
const int MM = 3005;
int psa[MM][MM];
int rectangle(int R, int C, int H, int W, int G[3001][3001]){
	int l = 1, r = R * C;
	while(l < r){
		int mid = (l + r) >> 1;
		int mx = 0;
		for (int i = 1; i <= R; i++)
			for (int j = 1; j <= C; j++)
				psa[i][j] = (G[i - 1][j - 1] <= mid) + psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
		for (int i = H; i <= R; i++)
			for (int j = W; j <= C; j++)
				mx = max(mx, psa[i][j] - psa[i - H][j] - psa[i][j - W] + psa[i - H][j - W]);
		if (mx >= (H * W + 1) / 2) r = mid;
		else l = mid + 1;
	}
	return l;
}
int main(){}
				
	
