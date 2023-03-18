#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){
    int n; 
    long long k;
    cin >> n >> k;
    if (k == 1LL * n * (n - 1) / 2){
        for (int i = n; i; i--) cout << i << ' ';
        return 0;
    }
    vector<int> a;
    for (int i = 1; i <= n; i++){
        if (k >= i - 1) a.push_back(i), k -= i - 1;
        else {
            reverse(a.begin(), a.end());
            a.insert(a.begin() + i - k - 1, i);
            for (int j = i + 1; j <= n; j++) a.push_back(j);
            break;
        }
    }
    for (int x : a) cout << x << ' ';
}

