#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
string str, ans;
int n;
int main(){
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(str); n = str.size(); ans = str;
    for (int i = 0; i < n - 2; i++){
		for (int j = i + 1; j < n - 1; j++){
			string t1 = str.substr(0, i + 1), t2 = str.substr(i + 1, j - i), t3 = str.substr(j + 1, n - j);
			reverse(af(t1)); reverse(af(t2)); reverse(af(t3));
			ans = min(ans, t1 + t2 + t3);
		}
	}
    pr(ans);
    return 0;
}

