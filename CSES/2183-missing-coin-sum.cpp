#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());
    long long sum = 0;
    for (int x : a){
        if (sum + 1 < x) break;
        sum += x;
    }
    cout << sum + 1 << '\n';
}

