#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int x = 0, y = 0;
        while(n--) cin >> y, x ^= y;
        cout << (x ? "first" : "second") << '\n';
    }
}
    
