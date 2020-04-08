#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int a[2][2] = {{1, 2}, {3, 4}};
    int v = 0, h = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == 'V') v++;
        else h++;
    }
    if (v % 2 == 0) {
        if (h % 2 == 0){
            for (int i = 0; i < 2; i++){
                for (int j = 0; j < 2; j++){
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
        }
        else {
            for (int i = 1; i >= 0; i--){
                for (int j = 0; j < 2; j++){
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    else {
        if (h % 2 == 0){
            for (int i = 0; i < 2; i++){
                for (int j = 1; j >= 0; j--){
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
        }
        else {
            for (int i = 1; i >= 0; i--){
                for (int j = 1; j >= 0; j--){
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}