#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
const char sp=' ',nl='\n';
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
const int mod = 1e9 + 7, base = 131;
int N, G, ans, cnt[1<<22]; bool g[11][11];
void flip(int x, int y){
	for (int i = x; i <= x + 1; i++)
		for (int j = y; j <= y + 1; j++)
			g[i][j] ^= 1;
}
int main(){
	sc(N, G);
	while(G--){
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++){
				char c; sc(c);
				g[i][j] = c == 'R';
			}
		for (int i = 0; i < N - 1; i++)
			for (int j = 0; j < N - 1; j++)
				if (g[i][j]) flip(i, j);
		int mask = 0;
		for (int i = 0; i < N; i++) mask |= g[i][N - 1] << i;
		for (int i = 0; i < N; i++) mask |= g[N - 1][i] << (i + N);
		ans += cnt[mask]; cnt[mask]++;
	}
	pr(ans);
	return 0;
}
