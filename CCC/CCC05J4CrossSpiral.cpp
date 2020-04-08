#include <bits/stdc++.h>
using namespace std;
int main()
{
    int l, w, sw, sl, steps;
    scanf("%d %d %d %d %d", &l, &w, &sl, &sw, &steps);
    bool spiral[w][l];
    memset(spiral, 0, sizeof(spiral));
    for (int i = 0; i < sw; i++){
        for (int j = 0; j < sl; j++){
            spiral[i][j] = true;
            spiral[w - i - 1][j] = true;
            spiral[i][l - j - 1] = true;
            spiral[w - i - 1][l - j - 1] = true;
        }
    }
    int dir1[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}, dir2[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    int r = 0, c = sl;
    spiral[r][c] = true;
    bool excute = true;
    while (steps > 0 && excute){
        int turn = 0;
        int nextR, nextC;
        if (c >= l / 2){
            nextR = r + dir1[turn][1], nextC = c + dir1[turn][0];
            while ((spiral[nextR][nextC] || nextR >= w || nextR < 0 || nextC >= l || nextC < 0)&& excute){
                turn++;
                if (turn == 4) excute = false;
                else {
                    nextR = r + dir1[turn][1];
                    nextC = c + dir1[turn][0];  
                }
            }
        }
        else {
            nextR = r + dir2[turn][1], nextC = c + dir2[turn][0];
            while ((spiral[nextR][nextC] || nextR >= w || nextR < 0 || nextC >= l || nextC < 0) && excute){
                turn++;
                if (turn == 4) excute = false;
                else {
                    nextR = r + dir2[turn][1];
                    nextC = c + dir2[turn][0];  
                }
            }
        }
        if(turn != 4){
            r = nextR; c = nextC;
            spiral[r][c] = true;
        }
        steps--;
    }
    printf("%d \n%d", c + 1, r + 1);
    return 0;
}