#include <bits/stdc++.h>
using namespace std;
int main()
{
    int loc[5];
    loc[0] = 0;
    for (int i = 1; i <= 4; i++){
        cin >> loc[i];
        loc[i] += loc[i - 1];
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cout << abs(loc[j] - loc[i]) << "\t";
        }
        cout <<endl;
    }
    return 0;
}