#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int record[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >>record[i][j];
        }
    }
    if (record[0][0] < record[0][1] && record[0][0] < record[1][0]){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout <<record[i][j] << "\t";
            }
            cout <<endl;
        }
    }
    else if (record[0][0] > record[0][1] && record[0][0] < record[1][0]){
        for (int i = n - 1; i >= 0; i--){
            for (int j = 0; j < n; j++){
                cout <<record[j][i] << "\t";
            }
            cout <<endl;
        }
    }
    else if (record[0][0] < record[0][1] && record[0][0] > record[1][0]){
        for (int i = 0; i < n; i++){
            for (int j = n - 1; j >= 0; j--){
                cout <<record[j][i] << "\t";
            }
            cout <<endl;
        }
    }
    else {
        for (int i = n - 1; i >= 0; i--){
            for (int j = n - 1; j >= 0; j--){
                cout <<record[i][j] << "\t";
            }
            cout <<endl;
        }
    }
    return 0;
}