#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> pii;
int N; ll ans;
stack<pii> s;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(N);
	for (int i = 0, a; i < N; i++){
		sc(a); 
		for (; !s.empty() && a > s.top().f; s.pop()) ans += s.top().s;
		if (!s.empty()){
			if (s.top().f == a){
				ans += s.top().s;
				if (sz(s) > 1) ans++;
			}
			else ans++;
		}
		if (!s.empty() && a == s.top().f) s.top().s++;
		else s.emplace(a, 1);
	}
	pr(ans);
	return 0;
}

