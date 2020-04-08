#include <bits/stdc++.h>
using namespace std;
int g, p, gate[100002];
int find(int x){
    if (x != gate[x]) gate[x] = find(gate[x]);
    return gate[x];
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> g >> p;
    for (int i = 1; i < g + 1; i++) gate[i] = i;
    for (int i = 0, x; i < p; i++){
        cin >> x;
        int y = find(x);
        if (!y){
            cout << i;
            return 0;
        }
        gate[y] = find(y - 1);
    }
    cout << p;
    return 0;
}