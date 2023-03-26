#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define INF 0x3f3f3f3f
#define nl '\n'
int T, M, a, b;
bool grid[5][5] = {{0,1,1,1,0},
                   {0,0,1,0,0},
                   {0,0,0,0,0},
                   {0,0,0,0,0},
                   {0,0,0,0,0}};
bool rec(int m, int x, int y){
    if (m == 1) return grid[y][x];
    int p = pow(5, m - 1);
    int nr = y / p, nc = x / p;
    if (nr == 1 && nc == 1 || nr == 2 && nc == 2 || nr == 1 && nc == 3){
        int nx = x % p, ny = y % p;
        return rec(m - 1, nx, ny);
    }
    return grid[nr][nc];
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while(T--){
        cin >> M >> a >> b;
        if (rec(M, a, b)) cout << "crystal" << nl;
        else cout << "empty" << nl;
    }
    return 0;
}