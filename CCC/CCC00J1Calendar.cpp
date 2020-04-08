#include <bits/stdc++.h>
using namespace std;
int n, days, pos = 1;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> days;
    cout << "Sun Mon Tue Wed Thr Fri Sat" << endl;
    for (int i = 0; i < n - 1; i++){
        cout << "    ";
        pos++;
    }
    for (int x = 1; x <= days; x++){
        if (x < 10) cout << "  " << x;
        else cout << " " << x;
        if (pos == 7 || x == days) cout << endl;
        else cout << ' ';
        pos++;
        if (pos == 8) pos = 1;
    }
    return 0;
}