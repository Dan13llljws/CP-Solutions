#include <bits/stdc++.h>
using namespace std;
int n;
char grid[30][30];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int cnt = 0; char c = grid[i][j]; 
            if (c == '.') continue;
            for (int k = i; k < n; k++){
                if (grid[k][j] == c) cnt++;
                else break;
            }
            if (cnt >= 3){
                cout << c;
                return 0;
            }
            cnt = 0;
            for (int k = j; k < n; k++){
                if (grid[i][k] == c) cnt++;
                else break;
            }
            if (cnt >= 3){
                cout << c;
                return 0;
            }
            cnt = 0;
            for (int k = i, l = j; k < n && l < n; k++, l++){
                if (grid[k][l] == c) cnt++;
                else break;
            }
            if (cnt >= 3){
                cout << c;
                return 0;
            }
            cnt = 0;
            for (int k = i, l = j; k >= 0 && l < n; k--, l++){
                if (grid[k][l] == c) cnt++;
                else break;
            }
            if (cnt >= 3){
                cout << c;
                return 0;
            }
        }
    }
    cout << "ongoing";
    return 0;
}