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
#define af(x) x.begin(), x.end()
int T, n, k;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while(T--){
        cout << "The bit patterns are" << nl;
        cin >> n >> k;
        string s;
        FOR(i, n){
            if (i < k) s += '1';
            else s += '0';
        }
        do{
            cout << s << nl;
        }while(prev_permutation(af(s)));
        cout << nl;
    }
    return 0;
}