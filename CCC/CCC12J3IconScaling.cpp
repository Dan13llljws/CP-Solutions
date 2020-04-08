#include <bits/stdc++.h>
using namespace std;
int main()
{
    char sbl[3][3] = {{'*', 'x', '*'},{' ', 'x', 'x'},{'*', ' ', '*'}};
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < 3; k++){
                for (int l = 0; l < n; l++){
                    printf("%c", sbl[i][k]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}