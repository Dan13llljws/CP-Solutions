#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
int n, psa[3][3][MM];
void init(string a, string b){
    n = a.size();
    for (int i = 0; i < n; i++){
        if (a[i] == 'T') a[i] = 'B';
        if (b[i] == 'T') b[i] = 'B';
    }
    for (int i = 0; i < n; i++){
        if (a[i] != b[i]) psa[a[i] - 'A'][b[i] - 'A'][i + 1]++;
        for (int j = 0; j < 3; j++) 
            for (int k = 0; k < 3; k++) 
                psa[j][k][i + 1] += psa[j][k][i];
    }
}
int get_distance(int x, int y){
    for (int i = 0; i < 3; i++){
        int s1 = 0, s2 = 0;
        for (int j = 0; j < 3; j++)
            s1 += psa[i][j][y + 1] - psa[i][j][x], s2 += psa[j][i][y + 1] - psa[j][i][x];
        if (s1 != s2) return -1;
    } return psa[1][2][y + 1] + psa[0][2][y + 1] - psa[1][2][x] - psa[0][2][x] 
        + max(psa[0][1][y + 1] - psa[0][1][x], psa[1][0][y + 1] - psa[1][0][x]);
}

