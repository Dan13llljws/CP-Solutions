#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 0, b = 0;
    for (int i = 3; i >= 1; i--){
        int x;
        cin >> x;
        a += x * i;
    }
    for (int i = 3; i >= 1; i--){
        int y;
        cin >> y;
        b += y * i;
    }
    if (a > b) cout << "A";
    else if (b > a) cout << "B";
    else cout << "T";
    return 0;
}