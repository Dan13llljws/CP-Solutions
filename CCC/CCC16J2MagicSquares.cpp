#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef unsigned long long ull;
int grid[4][4], sums[8];
bool magic = true;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            cin >> grid[i][j];
        }
        for (int j = 0; j < 4; j++){
            sums[i] += grid[i][j];
        }
    }
    for (int i = 4; i < 8; i++){
        for (int j = 0; j < 4; j++){
            sums[i] += grid[j][i - 4];
        }
    }
    for (int i = 1; i < 8; i++){
        if (sums[i] != sums[i - 1]) magic = false;
    }
    if (magic) cout << "magic\n";
    else cout << "not magic\n";

    return 0;
}
