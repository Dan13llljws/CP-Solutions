#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 5e5 + 5;
int n, ans, b[MM], a[MM], p[MM]; set<int> s; vector<int> v[MM];
int main(){ 
	n = re;
	for (int i = 0; i < n; i++) a[i] = re - 1;
	for (int i = 0; i < n; i++) p[i] = re;
	for (int i = 0; i < n; i++) v[a[i]].push_back(re);
	for (int i = 0; i < 2 * n; i++){
		int cur = i % n;
		for (int x : v[cur]) s.insert(x);
		v[cur].clear();
		if (s.empty()) continue;
		auto it = s.lower_bound(p[cur]);
		if (b[cur]){
			if (b[cur] > p[cur] && (it == s.end() || *it > b[cur])) continue;
			if (*it > p[cur] && (*it < b[cur] || b[cur] < p[cur])) ans += b[cur] < p[cur], s.insert(b[cur]), b[cur] = *it, s.erase(it);
			else if (b[cur] < p[cur] && *s.begin() < b[cur]) s.insert(b[cur]), b[cur] = *s.begin(), s.erase(s.begin());
		} else {
			if (it == s.end()) b[cur] = *s.begin(), s.erase(s.begin());
			else b[cur] = *it, s.erase(it), ans++;
		}
	}
	printf("%d\n", ans);
}
