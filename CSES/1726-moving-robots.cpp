#include <bits/stdc++.h>
using namespace std;
double p[8][8][8][8];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bool inside(int x, int y){
    return x >= 0 && y >= 0 && x < 8 && y < 8;
}
int main(){
    int k;
    cin >> k;
    for (int x = 0; x < 8; x++)
        for (int y = 0; y < 8; y++)
            p[x][y][x][y] = 1;
    for (int x = 0; x < 8; x++)
        for (int y = 0; y < 8; y++){
            for (int t = 0; t < k; t++){
                vector<vector<double>> pp(8, vector<double>(8));
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++){
                        int cnt = 0;
                        for (int d = 0; d < 4; d++){
                            int nx = i + dx[d], ny = j + dy[d];
                            cnt += inside(nx, ny);
                        }
                        for (int d = 0; d < 4; d++){
                            int nx = i + dx[d], ny = j + dy[d];
                            if (inside(nx, ny)) pp[nx][ny] += p[x][y][i][j] / cnt;
                        }
                    }
                for (int i = 0; i < 8; i++)
                    for (int j = 0; j < 8; j++)
                        p[x][y][i][j] = pp[i][j];
            }
        }
    double ans = 0;
    for (int x = 0; x < 8; x++)
        for (int y = 0; y < 8; y++){
            double prob = 1;
            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                    prob *= (1 - p[i][j][x][y]);
            ans += prob;
        }
    cout << fixed << setprecision(6) << ans << '\n';
}

