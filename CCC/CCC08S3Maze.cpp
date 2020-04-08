#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(x, y) memset((x), (y), sizeof(x))
#define mp make_pair
#define pb push_back
#define nl '\n'
char _;
typedef pair<int, int> pii;
typedef long long ll;
char maze[21][21];
int t, dist[21][21], vis[21][21];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        ms(dist, 0); ms(vis, 0);
        int r, c; cin >> r >> c;
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                cin >> maze[i][j];
            }
        }
        queue<pii> q;
        dist[0][0] = 1; vis[0][0] = 1;
        q.push(mp(0, 0));
        while(!q.empty()){
            int nr = q.front().first, nc = q.front().second;
            q.pop();
            if (nc - 1 >= 0 && !vis[nr][nc - 1] && maze[nr][nc - 1] != '*' && (maze[nr][nc] == '-' || maze[nr][nc] == '+')){
                vis[nr][nc - 1] = 1;
                dist[nr][nc - 1] = dist[nr][nc] + 1;
                q.push(mp(nr, nc - 1));
            }
            if (nc + 1 < c && !vis[nr][nc + 1] && maze[nr][nc + 1] != '*' && (maze[nr][nc] == '-' || maze[nr][nc] == '+')){
                vis[nr][nc + 1] = 1;
                dist[nr][nc + 1] = dist[nr][nc] + 1;
                q.push(mp(nr, nc + 1));
            }
            if (nr - 1 >= 0 && !vis[nr - 1][nc] && maze[nr - 1][nc] != '*' && (maze[nr][nc] == '|' || maze[nr][nc] == '+')){
                vis[nr - 1][nc] = 1;
                dist[nr - 1][nc] = dist[nr][nc] + 1;
                q.push(mp(nr - 1, nc));
            }
            if (nr + 1 < r && !vis[nr + 1][nc] && maze[nr + 1][nc] != '*' && (maze[nr][nc] == '|' || maze[nr][nc] == '+')){
                vis[nr + 1][nc] = 1;
                dist[nr + 1][nc] = dist[nr][nc] + 1;
                q.push(mp(nr + 1, nc));
            }
            if (vis[r - 1][c - 1]){
                cout << dist[r - 1][c - 1] << nl;
                break;
            }
        }
        if (!vis[r - 1][c - 1]) cout << -1 << nl;
    }
    return 0;
}