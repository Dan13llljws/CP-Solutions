#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e7 + 5;
ll p[MM], s[MM];
ll delivery(int N, int K, int L, int positions[]){
    for (int i = 1; i <= N; i++)
        p[i] = p[max(0, i - K)] + 2 * positions[i - 1];
    ll ans = min(p[N], L + p[N - K]);
    for (int i = N; i; i--){
        s[i] = s[min(N + 1, i + K)] + 2 * (L - positions[i - 1]);
        ans = min(ans, p[i - 1] + s[i]);
        if (i - K > 0) ans = min(ans, p[i - K - 1] + L + s[i]);
    } return ans;
}
int main(){}
