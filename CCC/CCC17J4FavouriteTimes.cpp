#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef unsigned long long ull;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int d, counter = 0, h = 12, m = 0;
    cin >> d;
    if (d >= 720) {
        counter += d / 720 * 31;
        d = d % 720;
    }
    for (int i = 0; i < d; i++){
        m++;
        if (m == 60){
            m = 0;
            h++;
        }
        if (h == 13) h = 1;
        int w, x, y ,z;
        if (h < 10){
            x = h;
            if (m < 10) {y = 0; z = m;}
            else {y = m / 10; z = m % 10;}
            if (y - x == z - y) counter++;
        }
        else {
            w = h / 10; x = h % 10;
            if (m < 10) {y = 0; z = m;}
            else {y = m / 10; z = m % 10;}
            if (x - w == y - x && y - x == z - y) counter++;
        }
    }
    cout << counter;
    return 0;
}