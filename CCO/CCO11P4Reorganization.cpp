#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e5 + 5;
int n, r[MM], cnt[MM]; set<pii, greater<pii>> s;
int main(){
	n = re;
	for (int i = 1; i <= n; i++) r[i] = re;
	s.insert({r[1], 1});
	for (int i = 2; i <= n; i++){
		auto it = s.lower_bound({r[i], i});
		if (it == s.end()) return 0 * puts("NO");
		pii p = *it; cnt[p.second]++;
		if (cnt[p.second] == 2) s.erase(it);
		s.insert({r[i], i});
	}
	puts("YES");
}

