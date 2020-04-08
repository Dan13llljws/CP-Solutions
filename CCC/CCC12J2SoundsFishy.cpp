#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main(){
    cin >> a >> b >> c >> d;
    if (a > b && b > c && c > d) cout << "Fish Diving";
    else if (a < b && b < c && c < d) cout << "Fish Rising";
    else if (a == b && b == c && c == d) cout << "Fish At Constant Depth";
    else cout << "No Fish";
}