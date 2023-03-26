#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool well[400][200];
    well[200][0] = true;
    well[200][1] = true;
    well[200][2] = true;
    well[201][2] = true;
    well[202][2] = true;
    well[203][2] = true;
    well[203][3] = true;
    well[203][4] = true;
    well[204][4] = true;
    well[205][4] = true;
    well[205][3] = true;
    well[205][2] = true;
    well[206][2] = true;
    well[207][2] = true;
    well[207][3] = true;
    well[207][4] = true;
    well[207][5] = true;
    well[207][6] = true;
    well[206][6] = true;
    well[205][6] = true;
    well[204][6] = true;
    well[203][6] = true;
    well[202][6] = true;
    well[201][6] = true;
    well[200][6] = true;
    well[199][6] = true;
    well[199][5] = true;
    well[199][4] = true;
    char cmd; int steps;
    cin >> cmd >> steps;
    int x = 199, y = 4;
    bool isOk = true;
    while (cmd != 'q' && isOk){
        while(steps > 0){
            if(cmd == 'l'){
                x--;
                if(well[x][y]){
                    isOk = false;
                }
                else well[x][y] = true;
                steps--;
            }
            else if(cmd == 'r'){
                x++;
                if(well[x][y]){
                    isOk = false;
                }
                else well[x][y] = true;
                steps--;
            }
            else if(cmd == 'd'){
                y++;
                if(well[x][y]){
                    isOk = false;
                }
                else well[x][y] = true;
                steps--;
            }
            else{
                y--;
                if(well[x][y]){
                    isOk = false;
                }
                else well[x][y] = true;
                steps--;
            }
        }
        if(isOk) cout << x - 200<< " "<< (y + 1) * (-1)<< " safe"<<endl;
        else cout<< x - 200<< " "<< (y + 1) * (-1)<< " DANGER"<<endl;
        cin >> cmd >> steps;
    }
    return 0;
}