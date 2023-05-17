#include <bits/stdc++.h>
using namespace std;
void solve(int n, int start, int target){
    if (!n) return;
    solve(n - 1, start, 6 - target - start);
    cout << start << ' ' << target << '\n';
    solve(n - 1, 6 - target - start, target);
}
int main(){
    int n;
    cin >> n;
    cout << (1 << n) - 1 << '\n';
    solve(n, 1, 3);
}
