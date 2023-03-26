#include <bits/stdc++.h>
using namespace std;
int r, c, m, dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char grid[400][100], step[30000];
void solve(int cr, int cc, int d){
    for (int i = 0; i < m; i++){
        if (step[i] == 'F'){
            int nr = cr + dir[d][0], nc = cc + dir[d][1];
            if (nr >= 0 && nr < r && nc >= 0 && nc < c && grid[nr][nc] != 'X')
                cr += dir[d][0], cc += dir[d][1];
            else return;
        }
        else if (step[i] == 'R') d = (d + 3) % 4;
        else d = (d + 1) % 4;
    }
    grid[cr][cc] = '*';
}
int main(){
    scanf("%d%d", &r, &c); 
    for (int i = 0; i < r; i++) scanf("%s", grid[i]);
    scanf("%d", &m); getchar();
    for (int i = 0; i < m; i++, getchar()) step[i] = getchar();
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (grid[i][j] != 'X')
                for (int k = 0; k < 4; k++) solve(i, j, k);
    for (int i = 0; i < r; i++) puts(grid[i]);
}
