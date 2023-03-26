#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f; const char sp=' ',nl='\n';
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define re read()
#define sz(x) (int)(x.size())
const int mod = 1e9 + 7, base = 131, MM = 1e5 + 5;
int n, m; ll ans; set<int> s[MM];
int main(){
	n = re, m = re;
	for (int i = 0; i < m; i++){
		int a = re, b = re;
		s[a].insert(b);
	}
	for (int i = 1; i <= n; i++){
		ans += sz(s[i]); 
		if (!sz(s[i])) continue;
		int j = *s[i].begin(); s[i].erase(j);
		if (sz(s[i]) > sz(s[j])) swap(s[i], s[j]);
		for (auto x : s[i]) s[j].insert(x);
	}
	pr(ans, nl);
	return 0;
}
