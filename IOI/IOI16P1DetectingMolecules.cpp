#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, MM = 2e5 + 5;
long long sum; pair<int,int> p[MM];
int find_subset(int l, int u, int w[], int n, int result[]){
    for (int i = 0; i < n; i++) p[i] = {w[i], i};
    sort(p, p + n); 
    for (int i = 0, j = 0; i < n; i++){
        sum += p[i].first;
        while(sum > u) sum -= p[j++].first;
        if (sum >= l){
            for (int k = j; k <= i; k++) result[k - j] = p[k].second;
            return i - j + 1;
        }
    } return 0;
}
