#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> r(n);
    for (int &x : r) cin >> x;
    long double ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++){
            int p = 0;
            if (r[i] <= r[j]) p = r[i] * (r[i] - 1) / 2;
            else p = (r[j] - 1) * r[j] / 2 + (r[i] - r[j]) * r[j];
            ans += (long double)p / (r[i] * r[j]);
        }
    cout << fixed << setprecision(6) << (double)ans << '\n';
}

