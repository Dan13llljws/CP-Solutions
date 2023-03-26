#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5 + 5;
int besthub(int R, int L, int X[], ll B){
    int l = 1, r = R; 
    while(l < r){
        int mid = (l + r + 1) >> 1, m = (mid - 1) / 2; ll res = 0, cur = 0;
        for (int i = 0; i < mid; i++) cur += abs(X[i] - X[m]);
        res = cur;
        for (int i = 1, j = mid; j < R; i++, j++, m++){
            if (!(mid & 1)) cur -= (X[m + 1] - X[m]);
            cur += X[j] - X[m + 1] - X[m] + X[i - 1];
            res = min(res, cur);
        }
        if (res <= B) l = mid;
        else r = mid - 1;
    } return l;
}
int main(){
    int a[5] = {1, 2, 10, 12, 14};
    cout << besthub(5, 20, a, 6) << endl;
}
