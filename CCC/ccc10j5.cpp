#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, dist[9][9];
int dir[8][2] = {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
queue<pair<int, int>> q;
int main(){
    scanf("%d%d%d%d", &a, &b, &c, &d);
    memset(dist, 0x3f, sizeof dist);
    q.push({a, b}); dist[a][b] = 0;
    while(!q.empty()){
        int x = q.front().first, y = q.front().second; q.pop();
        if (x == c && y == d) return 0 * printf("%d", dist[x][y]);
        for (int k = 0; k < 8; k++){
            int nx = x + dir[k][0], ny = y + dir[k][1];
            if (nx < 1 || nx > 8 || ny < 1 || ny > 8 || dist[nx][ny] < dist[x][y] + 1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
}
