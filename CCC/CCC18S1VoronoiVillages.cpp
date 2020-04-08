#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >>n;
    double villages[n];
    double neib[n];
    for (int i = 0; i < n; i++){
        cin >>villages[i];
    }
    sort(villages, villages + n);
    neib[0] = -1;
    neib[n - 1] = -1;
    for (int i = 1; i < n - 1; i++){
        neib[i] = (villages[i] - villages[i - 1])/2 + (villages[i + 1] - villages[i])/2;
    }
    sort(neib, neib + n);
    printf("%.1f", neib[2]);
    return 0;
    return 0;
}