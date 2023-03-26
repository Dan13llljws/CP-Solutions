#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
struct ant{
	char c; int d;
}ants[2][27];
int N, M, T;
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(N, M);
    for (int i = N - 1; i >= 0; i--){
		sc(ants[0][i].c); ants[0][i].d = 1;
	}
    for (int i = N; i < M + N; i++){
		sc(ants[0][i].c); ants[0][i].d = -1;
	}
	sc(T);
	for (int i = 0; i < T; i++){
		for (int j = 0; j < N + M; j++){
			if (ants[0][j].d == 1 && ants[0][j + 1].d == -1){
				ants[1][j] = ants[0][j + 1], ants[1][j + 1] = ants[0][j];
				j++;
			}
			else ants[1][j] = ants[0][j];
		}
		memcpy(ants[0], ants[1], sizeof(ants[0]));
	}
	for (int i = 0; i < N + M; i++) pr(ants[0][i].c);
    return 0;
}
