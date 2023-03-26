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
int n;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while(n--){
        int nCar; cin >> nCar;
        stack<int> top, branch;
        bool ok = 1;
        for (int i = 0, a; i < nCar; i++){
            cin >> a; top.push(a);
        }
        int cur = 1;
        while(!top.empty()){
            if (!branch.empty() && top.top() > branch.top()){
                ok = 0;
                break;
            }
            branch.push(top.top());
            top.pop();
            while(!branch.empty() && branch.top() == cur){
                branch.pop();
                cur++;
            }
        }
        cout << (ok ? 'Y' : 'N') << nl;
    }
    return 0;
}