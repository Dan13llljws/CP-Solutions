#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while(n){
        int counter = 0;
        for (int i = 1; i < n; i++){
            counter += floor(sqrt(n * n - i * i));
        }
        counter += n;
        cout << 4 * counter + 1 << '\n';
        cin >> n;
    }
    return 0;
}