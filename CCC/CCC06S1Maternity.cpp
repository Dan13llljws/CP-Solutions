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
string mom, dad, kid;
int n;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> dad >> mom >> n;
    while(n--){
        cin >> kid;
        int flag = 1;
        for (int i = 0; i < 5; i++){
            if (kid[i] >= 'A' && kid[i] <= 'E'){
                if (dad[i * 2] >= 'A' && dad[i * 2] <= 'E' || dad[i * 2 + 1] >= 'A' && dad[i * 2 + 1] <= 'E'
                    || mom[i * 2] >= 'A' && mom[i * 2] <= 'E' || mom[i * 2 + 1] >= 'A' && mom[i * 2 + 1] <= 'E')
                        continue;
                else {
                    flag = 0;
                    break;
                }
            }
            else{
                if ((dad[i * 2] >= 'a' && dad[i * 2] <= 'e' || dad[i * 2 + 1] >= 'a' && dad[i * 2 + 1] <= 'e')
                    && (mom[i * 2] >= 'a' && mom[i * 2] <= 'e' || mom[i * 2 + 1] >= 'a' && mom[i * 2 + 1] <= 'e'))
                        continue;
                else {
                    flag = 0;
                    break;
                }
            }
        }
        cout << (flag ? "Possible baby." : "Not their baby!") << nl;
    }
    return 0;
}