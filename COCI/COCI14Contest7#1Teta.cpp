#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
int k, menu[21], x, t, s[21], in[21], freq[21], mx;
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(k);
    for (int i = 1; i <= k; i++) sc(menu[i]);
    sc(x);
    for (int i = 0, a; i < 4; i++){sc(a); in[a]++;}
    sc(t);
    for (int i = 0, a; i < t; i++){
		sc(a);
		if (!in[a]) for (int i = 1; i <= 20; i++) s[i] += menu[a];
		else {
			freq[a]++; mx = max(mx, freq[a]);
			for (int i = 1; i < freq[a]; i++) s[i] += menu[a];
		}
		s[0] += menu[a];
	}
	for (int i = 1; i <= mx; i++) s[0] = min(s[0], s[i] + x * i);
	pr(s[0]);
    return 0;
}
