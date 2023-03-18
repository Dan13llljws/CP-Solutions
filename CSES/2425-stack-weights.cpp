#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> sum(4 * n), mx(4 * n, -1e9), mn(4 * n, 1e9);
    function<void(int,int,int,int,int)> upd = [&](int i, int p, int v, int l1, int r1){
        if (l1 == r1){sum[i] = mx[i] = mn[i] = v; return;}
        int mid = (l1 + r1) >> 1;
        if (p <= mid) upd(i << 1, p, v, l1, mid);
        else upd(i << 1 | 1, p, v, mid + 1, r1);
        sum[i] = sum[i << 1] + sum[i << 1 | 1];
        mx[i] = max(mx[i << 1], sum[i << 1] + mx[i << 1 | 1]);
        mn[i] = min(mn[i << 1], sum[i << 1] + mn[i << 1 | 1]);
    };
    int lc = 0, rc = 0, lm = 0, rm = 0;
    for (int i = 0; i < n; i++){
        int p, x;
        cin >> p >> x;
        if (x == 2) x = -1, rc++, rm = max(rm, p);
        else lc++, lm = max(lm, p);
        upd(1, n - p, x, 0, n - 1);
        if (lc > rc){
            if (mn[1] >= 0) cout << ">\n";
            else cout << "?\n";
        } else if (lc < rc){
            if (mx[1] <= 0) cout << "<\n";
            else cout << "?\n";
        } else {
            if (lm > rm) cout << (mn[1] >= 0 ? '>' : '?') << '\n';
            else cout << (mx[1] <= 0 ? '<' : '?') << '\n';
        }
    }
//     -1 1 0
}
