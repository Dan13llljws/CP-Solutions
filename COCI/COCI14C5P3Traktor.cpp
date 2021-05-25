#include <bits/stdc++.h>
using namespace std;
const int M = 100005;
int n, k, rs[M], cs[M], ld[2 * M], rd[2 * M];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 1, a, b; i < n + 1; i++){
        cin >> a >> b;
        rs[b]++; cs[a]++;
        rd[a - b + M]++; ld[a + b]++;
        if (rs[b] == k || cs[a] == k || rd[a - b + M] == k || ld[a + b] == k){
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}