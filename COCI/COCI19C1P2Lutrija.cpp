#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
ll a, b; vector<ll> ans;
bool prime(ll x){
	if (x == 1) return 0;
	if (x == 2) return 1;
	if (x % 2 == 0) return 0;
	for (ll i = 3; i * i <= x; i += 2)
		if (x % i == 0) return 0;
	return 1;
}
int main(){
	a = re, b = re; ans.push_back(a);
	if (a != 2){
		if (prime(a - 2)){
			ans.push_back(2);
		} else if (prime(a + 2)){
			ans.push_back(a + 2);
			ans.push_back(2);
		} else return 0 * puts("-1");
	}
	if (b != 2){
		if (prime(b - 2)){
			ans.push_back(b);
		} else if (prime(b + 2)){
			ans.push_back(b + 2);
			ans.push_back(b);
		} else return 0 * puts("-1");
	}
	printf("%d\n", ans.size());
	for (ll v : ans) printf("%lld ", v);
}

