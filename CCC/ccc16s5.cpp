#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
#define flood(x) ms(x, 0x3f)
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
typedef long long ll;
ll N, T; bool circle[100010], tmp[100010];
string s;
void update(int k){
    int t1 = (1 << k) % N;
    int t2 = (N - t1) % N;
    for (int i = 0; i < N; i++){
        tmp[i] = circle[(i + t1) % N] ^ circle[(i + t2) % N];
    }
    memcpy(circle, tmp, sizeof circle);
    for (int i = 0; i < N; i++) pr(circle[i]); cout << endl;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(N, T, s);
    for (int i = 0; i < N; i++) circle[i] = s[i] - '0';
    for (int i = 64; i > 0; i--){
        if ((T >> i) & 1) update(i);
    }
    for (int i = 0; i < N; i++) pr(circle[i]);
    return 0;
}
