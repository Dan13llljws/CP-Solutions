#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
int N, M, g[1010][1010]; bool vis[1010][1010], cheese[1000001];
queue<pii> q;
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sc(N, M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            sc(g[i][j]);
    q.push(mp(1, 1));
    vis[1][1] = 1;
    while(!q.empty()){
        int x = q.front().f, y = q.front().s; q.pop();
        if (cheese[g[x][y]]) continue;
        if (vis[N][M]) break;
        cheese[g[x][y]] = 1;
        for (int i = 1; i * i <= g[x][y] && i <= max(N, M); i++){
            if (g[x][y] % i == 0){
                int nx = i, ny = g[x][y] / i;
                if (nx <= N && ny <= M && !vis[nx][ny]){
                    vis[nx][ny] = 1;
                    q.push(mp(nx, ny));
                }
                if (nx <= M && ny <= N && !vis[ny][nx]){
					vis[ny][nx] = 1;
					q.push(mp(ny, nx));
				}
            }
        }
    }
    if (vis[N][M]) pr("yes\n");
    else pr("no\n");
    return 0;
}
