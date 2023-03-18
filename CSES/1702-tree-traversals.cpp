#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n), pos(n + 1);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    for (int i = 0; i < n; i++) pos[b[i]] = i;
    function<void(int,int,int)> rec = [&](int s, int bl, int br){
        if (bl > br) return;
        if (bl == br){
            cout << b[bl] << ' ';
            return;
        }
        int rt = a[s], id = pos[rt];
        rec(s + 1, bl, id - 1), rec(s + id - bl + 1, id + 1, br);
        cout << rt << ' ';
    };
    rec(0, 0, n - 1);
}

