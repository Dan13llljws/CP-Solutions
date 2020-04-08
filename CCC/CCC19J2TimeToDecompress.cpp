#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        char y;
        cin >> y;
        for (int j = 0; j < x; j++){
            cout << y;
        }
        cout << endl;
    }
    return 0;
}