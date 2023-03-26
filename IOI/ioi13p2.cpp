#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 505;
int T, h, w, cc, mcs, vis[MM][MM], a[MM][MM], r[MM][MM], g[MM][MM], b[MM][MM]; ll sum;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int getR(int RGB) { return (RGB >> 16) & 0xFF; }
int getG(int RGB) { return (RGB >> 8) & 0xFF; }
int getB(int RGB) { return RGB & 0xFF; }
int main(){
     scanf("%d", &T);
    while(T--){
        scanf("%d%d", &h, &w), cc = mcs = 0;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++){
                scanf("%d", &a[i][j]), vis[i][j] = 0;
                r[i][j] = getR(a[i][j]), g[i][j] = getG(a[i][j]), b[i][j] = getB(a[i][j]);
                sum += r[i][j] + g[i][j] + b[i][j];
            }
        queue<pair<int,int>> q;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++){
                if (vis[i][j]) continue;
                cc++, vis[i][j] = 1, q.push({i, j});
                int cs = 0;
                while(q.size()){
                    int x = q.front().first, y = q.front().second; q.pop();
                    cs++;
                    for (int k = 0; k < 4; k++){
                        int nx = x + dx[k], ny =y + dy[k];
                        if (nx < 0 || ny < 0 || nx >= h || ny >= w || vis[nx][ny]) continue;
                        ll cur = abs(r[x][y] + g[x][y] + b[x][y] - r[nx][ny] - g[nx][ny] - b[nx][ny]);
                        if (cur > 40) continue;
                        vis[nx][ny] = 1, q.push({nx, ny});
                    }
                }
                mcs = max(mcs, cs);
            }
        sum /= h * w;
        if (mcs > 100000 && cc < 500) puts("4");
        else if (mcs < 20000 && cc > 10000) puts("3");
        else if (sum > 350) puts("1");
        else puts("2");
    }
}
