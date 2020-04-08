#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define mp make_pair
char _;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
int x, y, x2, y2, dist[9][9];
bool visited[9][9];
queue<pii> q;
int dir[2][8] = {{1, 2, 1, 2, -1, -2, -1, -2}, {2, 1, -2, -1, -2, -1, 2, 1}};
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> x >> y >> x2 >> y2;
    dist[x][y] = 0;
    visited[x][y] = 1;
    q.push(mp(x, y));
    while (!q.empty()){
        int a = q.front().first, b = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++){
            int c = a + dir[0][i], d = b + dir[1][i];
            if (!visited[c][d] && c < 9 && c > 0 && d < 9 && d > 0){
                visited[c][d] = 1;
                q.push(mp(c, d));
                dist[c][d] = dist[a][b] + 1;
            }
        }
        if (visited[x2][y2]){
            cout << dist[x2][y2];
            return 0;
        }
    }
    return 0;
}