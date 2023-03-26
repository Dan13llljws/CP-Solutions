#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
int n, s, q[MM], id[MM], tmp[MM]; double a[MM], b[MM], c[MM], x[MM], y[MM], dp[MM];
bool cmp(int i, int j){return a[j] * b[i] > a[i] * b[j];}
bool cmp1(int i, int j){return x[i] < x[j];}
double f(int i, int j){
    if (x[i] != x[j]) return (y[i] - y[j]) / (x[i] - x[j]);
    return y[i] > y[j] ? -1e20 : 1e20;
}
double calc(int i, int j){return a[i] * x[j] + b[i] * y[j];}
void cdq(int l, int r){
    if (l == r){
        dp[l] = max(dp[l], dp[l - 1]), y[l] = dp[l] / (a[l] * c[l] + b[l]);
        x[l] = y[l] * c[l]; return;
    } int mid = (l + r) >> 1;
    for (int i = l; i <= r; i++) tmp[i] = id[i];
    for (int i = l, j = l, k = mid + 1; i <= r; i++) 
        tmp[i] <= mid ? id[j++] = tmp[i] : id[k++] = tmp[i];
    cdq(l, mid); int l1 = 0, r1 = -1;
    for (int i = l; i <= mid; i++){
        while(l1 < r1 && f(q[r1], id[i]) > f(q[r1 - 1], q[r1])) r1--;
        q[++r1] = id[i];
    }
    for (int i = mid + 1; i <= r; i++){
        while(l1 < r1 && f(q[l1], q[l1 + 1]) > -a[id[i]] / b[id[i]]) l1++;
        dp[id[i]] = max(dp[id[i]], calc(id[i], q[l1]));
    } cdq(mid + 1, r), merge(id + l, id + mid + 1, id + mid + 1, id + r + 1, tmp + l, cmp1);
    for (int i = l; i <= r; i++) id[i] = tmp[i];
}
int main(){
    scanf("%d%d", &n, &s), dp[1] = s;
    for (int i = 1; i <= n; i++) scanf("%lf%lf%lf", a + i, b + i, c + i), id[i] = i;
    sort(id + 1, id + 1 + n, cmp), cdq(1, n); printf("%.3lf\n", dp[n]);
}
