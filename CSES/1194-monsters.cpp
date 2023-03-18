#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
string s = "DRUL";
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string> g(n);
	vector<vector<int>> dm(n, vector<int>(m, 1e9)), dist(n, vector<int>(m, 1e9)), pre(n, vector<int>(m, 5));
	queue<pair<int, int>> q;
	pair<int, int> start;
	for (int i = 0; i < n; i++){
		cin >> g[i];
		for (int j = 0; j < m; j++){
			if (g[i][j] == 'M') 
				q.push({i, j}), dm[i][j] = 0;
			else if (g[i][j] == 'A')
				start = {i, j};
		}
	}
	while(!q.empty()){
		int x = q.front().first, y = q.front().second; q.pop();
		for (int i = 0; i < 4; i++){
			int nx = x + dir[i][0], ny = y + dir[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && dm[nx][ny] > dm[x][y] + 1 && g[nx][ny] != '#'){
				dm[nx][ny] = dm[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	q.push({start.first, start.second});
	dist[start.first][start.second] = 0;
	while(!q.empty()){
		int x = q.front().first, y = q.front().second; q.pop();
		if (!x || x == n - 1 || !y || y == m - 1){
			string ans = "";
			pair<int, int> cur = {x, y};
			int p = pre[x][y];
			while (p != 5){
				ans.push_back(s[p]);
				cur = {cur.first - dir[p][0], cur.second - dir[p][1]};
				p = pre[cur.first][cur.second];
			}
			reverse(ans.begin(), ans.end());
			cout << "YES\n";
			cout << dist[x][y] << '\n';
			cout << ans << '\n';
			return 0;
		}
		for (int k = 0; k < 4; k++){
			int nx = x + dir[k][0], ny = y + dir[k][1];
			if (x >= 0 && x < n && y >= 0 && y < m && dist[nx][ny] > dist[x][y] + 1 && 
				g[nx][ny] == '.' && dm[nx][ny] > dist[x][y] + 1){
				dist[nx][ny] = dist[x][y] + 1;
				pre[nx][ny] = k;
				q.push({nx, ny});
			}
		}
	}
	cout << "NO\n";
}
