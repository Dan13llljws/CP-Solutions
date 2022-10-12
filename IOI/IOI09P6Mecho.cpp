#include <bits/stdc++.h>
using namespace std;
const int MM = 805;
int n, s, sx, sy, h[MM][MM], vis[MM][MM], d[MM][MM]; char g[MM][MM]; 
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
bool check(int t){
    queue<pair<int,int>> q; q.push({sx, sy}), d[sx][sy] = t * s;
    memset(vis, 0, sizeof vis), vis[sx][sy] = 1; 
    while(q.size()){
        int x = q.front().first, y = q.front().second; q.pop();
        if (g[x][y] == 'D') return 1;
        int nxtd = (d[x][y] + 1) / s;
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (nx <= 0 || ny <= 0 || nx > n || ny > n || vis[nx][ny] || g[nx][ny] == 'T') continue;
            if (nxtd < h[nx][ny]) q.push({nx, ny}), d[nx][ny] = d[x][y] + 1, vis[nx][ny] = 1;
        }
    } return 0;
}
int main(){
    scanf("%d%d", &n, &s), memset(h, 0x3f, sizeof h); queue<pair<int,int>> q;
    for (int i = 1; i <= n; i++){
        scanf("%s", g[i] + 1);
        for (int j = 1; j <= n; j++)
            if (g[i][j] == 'H') h[i][j] = 0, q.push({i, j}), vis[i][j] = 1;
            else if (g[i][j] == 'M') sx = i, sy = j;
    } 
    while(q.size()){
        int x = q.front().first, y = q.front().second; q.pop();
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (nx <= 0 || ny <= 0 || nx > n || ny > n || vis[nx][ny] || g[nx][ny] == 'T' || g[nx][ny] == 'D') continue;
            q.push({nx, ny}), h[nx][ny] = h[x][y] + 1, vis[nx][ny] = 1;
        }
    } int l = -1, r = h[sx][sy] - 1;
    while(l < r){
        int mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    } printf("%d\n", l);
}


