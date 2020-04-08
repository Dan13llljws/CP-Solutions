#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define INF 0x3f3f3f3f
#define nl '\n'
#define For(i, a, b) for(int i=a; i<b; i++)
#define FOR(i, a) For(i, 0, a)
#define Forr(i, a, b) for(int i=a-1; i>=b; i--)
#define FORR(i, a) Forr(i, a, 0);
int n, a, b, c, cnt;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> a >> b >> c;
    while(1){
        cnt++; a++; n--;
        if (a == 35){
            n += 30;
            a = 0;
        }
        if (n <= 0){
            cout << "Martha plays " << cnt << " times before going broke." << nl;
            return 0;
        }
        cnt++; b++; n--;
        if (b == 100){
            n += 60;
            b = 0;
        }
        if (n <= 0){
            cout << "Martha plays " << cnt << " times before going broke." << nl;
            return 0;
        }
        cnt++; c++; n--;
        if (c == 10){
            n += 9;
            c = 0;
        }
        if (n <= 0){
            cout << "Martha plays " << cnt << " times before going broke." << nl;
            return 0;
        }
    }
    return 0;
}