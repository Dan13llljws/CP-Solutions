#include <bits/stdc++.h>
using namespace std;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    vector<vector<bool>> vis(n, vector<bool>(m));
    for (int i = 0; i < n; i++)
        cin >> g[i];
    int ans = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!vis[i][j] && g[i][j] != '#'){
                q.push({i, j});
                vis[i][j] = 1;
                ans++;
                while(!q.empty()){
                    int x = q.front().first, y = q.front().second; q.pop();
                     for (int k = 0; k < 4; k++){
                         int nx = x + dir[k][0], ny = y + dir[k][1];
                         if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && g[nx][ny] == '.')
                            vis[nx][ny] = 1, q.push({nx, ny});
                     }
                }
            }
    printf("%d\n", ans);
}
