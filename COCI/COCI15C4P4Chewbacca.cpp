#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
typedef long long ll;
ll N, K; int Q;
ll p[51], psa[51];
ll up(ll x, int lx){
	return psa[lx - 2] + 1 + (x - psa[lx - 1] - 1) / K;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(N, K, Q); p[1] = psa[1] = 1;
	for (int i = 2; psa[i - 1] <= N && K != 1; i++){
		p[i] = p[i - 1] * K;
		psa[i] = p[i] + psa[i - 1];
	}
	while(Q--){ 
		ll a, b; sc(a, b);
		if (K == 1){pr(abs(a - b), nl); continue;}
		int la = 0, lb = 0, ans = 0;
		for (int i = 1; i <= 51; i++)
			if (a > psa[i - 1] && a <= psa[i]){la = i; break;}
		for (int i = 1; i <= 51; i++)
			if (b > psa[i -1 ] && b <= psa[i]){lb = i; break;}
		
		if (la > lb) swap(la, lb), swap(a, b);
		while(lb != la) b = up(b, lb--), ans++;
		if (a == b) pr(ans, nl);
		else {
			while(a != b){
				a = up(a, la--);
				b = up(b, lb--);
				ans += 2;
			}
			pr(ans, nl);
		}
	}
	return 0;
}

