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
string s;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    getline(cin, s);
    while(s != "0"){
        stack<string> op;
        for (int i = s.size() - 1; i >= 0; i--){
            if (s[i] == ' ') continue;
            if (s[i] == '+' || s[i] == '-'){
                string op1 = op.top(); op.pop();
                string op2 = op.top(); op.pop();
                op.push(op1 + " " + op2 + " " + s[i]);
            }
            else {
                op.push(s.substr(i, 1));
            }
        }
        cout << op.top() << nl;
        getline(cin, s);
    }
    return 0;
}