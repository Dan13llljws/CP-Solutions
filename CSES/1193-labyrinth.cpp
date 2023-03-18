#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3 + 5;
string ans;
int n, m;
vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
string c = "DRUL";
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	vector<string> g(n);
	vector<vector<int>> dist(n, vector<int>(m, 1e9));
	vector<vector<int>> pre(n, vector<int>(m, 5));
	for (int i = 0; i < n; i++)
		cin >> g[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (g[i][j] == 'A'){
				queue<pair<int, int>> q;
				q.push({i, j});
				dist[i][j] = 0;
				while(!q.empty()){
					int x = q.front().first, y = q.front().second; q.pop();
					if (g[x][y] == 'B'){
						cout << "YES\n";
						pair<int, int> cur = {x, y}; 
						int p = pre[x][y];
						while(p != 5){
							ans.push_back(c[p]);
							cur = {cur.first - dir[p][0], cur.second - dir[p][1]};
							p = pre[cur.first][cur.second];
						}
						cout << ans.size() << '\n';
						reverse(ans.begin(), ans.end());
						cout << ans << '\n';
						return 0;
					}
					for (int k = 0; k < 4; k++){
						int nx = x + dir[k][0], ny = y + dir[k][1];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] > dist[x][y] + 1 && g[nx][ny] != '#')
							dist[nx][ny] = dist[x][y] +  1, pre[nx][ny] = k, q.push({nx, ny});
					}
				}
			}
	cout << "NO\n";
}
