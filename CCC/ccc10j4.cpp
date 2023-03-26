#include <bits/stdc++.h>
using namespace std;
int n, diff[25], x, y, cycleLength, cycle;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    while(cin >> n && n){
        if (n == 1){
            cin >> x;
            cout << 0 << '\n';
        }
        else {
            cin >> x;
            for (int i = 1; i < n; i++){
                cin >> y;
                diff[i] = y - x; x = y;
            }
            cycle = 0;
            for (cycleLength = 2; cycleLength < n; cycleLength++){
                if (diff[1] != diff[cycleLength]) continue;
                cycle = 1;
                for (int i = 2; cycleLength + i < n; i++){
                    if (diff[i] != diff[cycleLength + i - 1]){
                        cycle = 0;
                        break;
                    }
                }
                if (cycle){
                    cout << cycleLength - 1 << '\n';
                    break;
                }
            }
            if (!cycle) cout << n - 1 << '\n';
        }
    }
    return 0;
}