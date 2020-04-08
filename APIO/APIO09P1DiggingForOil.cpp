#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
const int MM = 1505;
int n, m, k, ans,s[MM][MM], mx[4][MM][MM];
int dir[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int get(int x, int y){
	return s[x][y] - s[x - k][y] - s[x][y - k] + s[x - k][y - k];
}
void get_max(int p, int a, int b){
	int x = dir[p][0], y = dir[p][1];
	for (int i = a; i && i <= n; i += x)
		for (int j = b; j && j <= m; j += y)
			if (p == 0) mx[0][i][j] = max({get(i, j), mx[0][i - 1][j], mx[0][i][j - 1]});
			else if (p == 1) mx[1][i][j] = max({get(i, j + k - 1), mx[1][i - 1][j], mx[1][i][j + 1]});
			else if (p == 2) mx[2][i][j] = max({get(i + k - 1, j), mx[2][i + 1][j], mx[2][i][j - 1]});
			else mx[3][i][j] = max({get(i + k - 1, j + k - 1), mx[3][i + 1][j], mx[3][i][j + 1]});
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(m, n, k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			sc(s[i][j]);
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	get_max(0, k, k); get_max(1, k, m - k + 1); get_max(2, n - k + 1, 1); get_max(3, n - k + 1, m - k + 1);
	for (int i = k; i + k <= n; i++)
		for (int j = k; j + k <= m; j++){
			int p1 = mx[0][i][j] + mx[2][i + 1][j] + mx[3][1][j + 1];
			int p2 = mx[0][i][j] + mx[1][i][j + 1] + mx[2][i + 1][m];
			int p3 = mx[0][n][j] + mx[1][i][j + 1] + mx[3][i + 1][j + 1];
			int p4 = mx[0][i][m] + mx[2][i + 1][j] + mx[3][i + 1][j + 1];
			ans = max({ans, p1, p2, p3, p4});
		}
	for (int j = k; j + 2 * k <= m; j++)
		for (int i = k; i <= n; i++)
			ans = max(ans, mx[0][n][j] + get(i, j + k) + mx[1][n][j + k + 1]);
	for (int i = k; i + 2 * k <= n; i++)
		for (int j = k; j <= m; j++)
			ans = max(ans, mx[0][i][m] + get(i + k, j) + mx[2][i + k + 1][m]);
	pr(ans, nl);
	return 0;
}
