#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
int n;
bool g[1001][1001];
int cnt(int x1, int y1, int x2, int y2){
	int cnt = 0;
	for (int i = x1; i <= x2; i++)
		for (int j = y1; j <= y2; j++)
			cnt += g[i][j];
	return cnt;
}
void flipR(int i){
	for (int j = 0; j < n; j++) g[i][j] ^= 1;
}
void flipC(int j){
	for (int i = 0; i < n; i++) g[i][j] ^= 1;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			char c; sc(c);
			g[i][j] = (c == 'L');
		}
	if (g[0][0]) flipR(0);
	for (int i = 1; i < n; i++)
		if (g[i][0]) flipR(i);
	for (int i = 1; i < n; i++)
		if (g[0][i]) flipC(i);
	if (cnt(1, 1, n - 1, n - 1) == (n - 1) * (n - 1)){pr(1, sp, 1); return 0;}
	if (cnt(1, 1, n - 1, n - 1) == n - 1){
		for (int i = 1; i < n; i++) if (cnt(i, 1, i, n - 1) == n - 1){pr(i + 1, sp, 1); return 0;}
		for (int i = 1; i < n; i++) if (cnt(1, i, n - 1, i) == n - 1){pr(1, sp, i + 1); return 0;}
		pr(-1); return 0;
	}
	if (cnt(1, 1, n - 1, n - 1) != 1){pr(-1); return 0;}
	for (int i = 1; i < n; i++)
		for (int j = 1; j < n; j++)
			if (g[i][j]) pr(i + 1, sp, j + 1); 
	return 0;
}
	
