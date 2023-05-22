#include <bits/stdc++.h>
using namespace std;
double fpow(double x, int k){
    double ret = 1;
    while(k){
        if (k & 1) ret = ret * x;
        x = x * x, k >>= 1;
    } return ret;
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<double> p(k + 1);
    for (int i = 1; i <= k; i++)
        p[i] = fpow(1.0 * i / k, n);
    double ans = 0;
    for (int i = k; i; i--){
        p[i] -= p[i - 1];
        ans += i * p[i];
    }
    cout << fixed << setprecision(6) << ans << '\n';
}
