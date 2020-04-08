#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define INF 0x3f3f3f3f
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define nl '\n'
char _;
int r, c, m, dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char grid[400][100], step[30000];
void solve(int cr, int cc, int init){
    int d = init;
    for (int i = 0; i < m; i++){
        if (step[i] == 'F'){
            int nr = cr + dir[d][0], nc = cc + dir[d][1];
            if (nr >= 0 && nr < r && nc >= 0 && nc < c && grid[nr][nc] != 'X'){
                cr += dir[d][0]; cc += dir[d][1];
            }
            else return;
        }
        else if (step[i] == 'R'){
            d--;
            if (d < 0) d = 3;
        }
        else{
            d++;
            if (d > 3) d = 0;
        }
    }
    grid[cr][cc] = '*';
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> r >> c;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> grid[i][j];
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> step[i];
    }
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (grid[i][j] != 'X'){
                for (int k = 0; k < 4; k++) solve(i, j, k);
            }
        }
    }
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << grid[i][j];
        }
        cout << nl;
    }
    return 0;
}