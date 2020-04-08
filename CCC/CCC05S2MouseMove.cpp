#include <bits/stdc++.h>
using namespace std;
int main() {
    double r, c; cin >> r >> c;
    double x, y; cin >> x >> y;
    double cr = 0, cc = 0;
    while(x != 0 || y != 0){
        cr += x; cc += y;
        if (cr < 0) cr = 0;
        if (cc < 0) cc = 0;
        if (cr > r) cr = r;
        if (cc > c) cc = c;
        cout << cr << ' ' << cc << '\n';
        cin >> x >> y;
    }
    return 0;
}