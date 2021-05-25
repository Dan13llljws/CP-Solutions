#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
int n; ll ans; set<pair<int, int>> s;
int main(){
	n = re; s.insert({0, 0}), s.insert({n + 1, 0});
	for (int i = 0; i < n; i++){
		int a = re;
		auto it = s.lower_bound({a, 0});
		int b = (*it).second, c = max(b, (*--it).second);
		ans += c; s.insert({a, c + 1});
		printf("%lld\n", ans);
	}
}
