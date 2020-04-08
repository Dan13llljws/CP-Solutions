#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef unsigned long long ull;
int n, x, y;
int piece[2001], height[4001];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0, a; i < n; i++){
        cin >> a;
        piece[a]++;
    }
    for (int i = 1; i <= 2000; i++){
        if (piece[i] > 0){
            for (int j = 1; j < i; j++){
                height[i + j] += min(piece[i], piece[j]);
            }
        }
        height[i + i] += piece[i] / 2;
    }
    for (int i = 1; i <= 4000; i++){
        if(height[i] > x){
            x = height[i];
            y = 1;
        }
        else if (height[i] == x) y++;
    }
    cout << x << " " << y;
    return 0;
}