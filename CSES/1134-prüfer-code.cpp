#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> prufer(n - 2), in(n);
    set<int> leaf;
    for (int i = 0; i < n; i++) leaf.insert(i);
    for (int &x : prufer) cin >> x, in[--x]++, leaf.erase(x);
    for (int x : prufer){
        int y = *leaf.begin();
        cout << x + 1 << ' ' << y + 1 << '\n';
        in[x]--, leaf.erase(y);
        if (!in[x]) leaf.insert(x);
    }
    for (int x : leaf) cout << x + 1 << ' ';
    cout << '\n';
}
