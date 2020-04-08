#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef unsigned long long ull;
int n, a[101];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    if (n % 2 == 0){
        for (int i = 0; i < n / 2; i++){
            cout << a[n / 2 - i - 1] << " " <<a[n / 2 + i] << " ";
        }
    }
    else {
        for (int i = 0; i < n / 2; i++){
            cout << a[n / 2 - i] << " " <<a[n / 2 + i + 1] << " ";
        }
        cout << a[0];
    }
    return 0;
}