#include <bits/stdc++.h>
using namespace std;
int spiral[12][12];
int main()
{
    int x, y;
    cin >>x >>y;
    int r = 6, c = 6, limit = 1, step = 0, turn = 0, d = 0;
    int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    spiral[r][c] = x;
    for (int i = x + 1; i <= y; i++){
        if(step < limit){
            r += dir[d][0]; c += dir[d][1];
            spiral[r][c] = i;
            step++;
        }
        else {
            d = (d + 1) % 4;
            turn++;
            step = 0;
            if(turn == 2){
                limit++;
                turn = 0;
            }
            i--;
        }
    }
    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 12; j++){
            if (spiral[i][j] != 0) cout <<spiral[i][j] << "\t";
            else cout << "\t";
        }
        cout <<endl;
    }
    return 0;
}