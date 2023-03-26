#include <bits/stdc++.h>
using namespace std;
int m, n, dp[101][101][2][2], grid[101][101];
int dfs(int x, int y, bool up, bool down){
    if (grid[x][y] == -1 || x < 0 || x >= n || y < 0 || y >= m) return -1e9;
    if (x == n - 1 && y == m - 1) return grid[x][y];
    int &tmp = dp[x][y][up][down];
    if (tmp != -1) return tmp;
    tmp = -1e9;
    if (!down) tmp = dfs(x - 1, y, 1, 0);
    if (!up) tmp = max(tmp, dfs(x + 1, y, 0, 1));
    tmp = max(tmp, dfs(x, y + 1, 0, 0));
    return tmp += grid[x][y];
}
int main(){    
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(1){
        cin >> n >> m;
        if (!m) break;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                char c; cin >> c;
                if (c == '.') grid[i][j] = 0;
                else if (c == '*') grid[i][j] = -1;
                else grid[i][j] = c - '0';
            }
        }
        memset(dp, -1, sizeof dp);
        cout << dfs(n - 1, 0, 0, 0) << endl;
    }
}