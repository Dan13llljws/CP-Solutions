#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define lc i << 1
#define rc i << 1 | 1
#define md int mid = (l1 + r1) >> 1
const int mod = 1e9 + 7, MM = 1e5 + 5;
int n, q, a[16], g[4][4], seg[MM<<2][16];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
void upd(int i, int p, int l1 = 1, int r1 = n){
	if (l1 == r1){
		for (int j = 0; j < 16; j++) seg[i][j] = a[j];
		return;
	} md;
	if (p <= mid) upd(lc, p, l1, mid);
	else upd(rc, p, mid + 1, r1);
	for (int j = 0; j < 16; j++) seg[i][j] = seg[lc][seg[rc][j]];
}
void rot(int r, int c, int k){
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			g[i][j] = i * 4 + j;
	int d = 0;
	for (int x = r, y = c, nx, ny; k > 1; x = nx, y = ny){
		nx = x + dx[d], ny = y + dy[d];
		while(nx < r || nx >= r + k || ny < c || ny >= c + k)
			d++, nx = x + dx[d], ny = y + dy[d];
		g[nx][ny] = x * 4 + y;
		if (nx == r && ny == c) break;
	}
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			a[i * 4 + j] = g[i][j];
}
int main(){
	n = re, q = re; 
	for (int i = 1, r, c, k; i <= n; i++) r = re - 1, c = re - 1, k = re, rot(r, c, k), upd(1, i);
	while(q--){
		int i = re, r = re - 1, c = re - 1, k = re; 
		rot(r, c, k), upd(1, i);
		for (int i1 = 0; i1 < 4; i1++)
			for (int j = 0; j < 4; j++) 
				printf("%d%c", seg[1][i1 * 4 + j] + 1, j == 3 ? '\n' : ' ');
	}
}
