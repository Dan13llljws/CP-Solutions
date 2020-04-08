#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define pb push_back
#define nl '\n'
char _;
typedef pair<int, int> pii;
typedef long long ll;
string s, ms; int t, mt = INT_MAX;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> s >> t;
    while(s != "Waterloo"){
        if (t < mt){
            mt = t;
            ms = s;
        }
        cin >> s >> t;
    }
    cout << ms << nl;
    return 0;
}