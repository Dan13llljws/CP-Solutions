#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e5 + 5;
struct S{int x, i;}s[MM];
struct Q{int s, d, i;}q[MM];
int n, b, mx, ans[MM]; set<pii> p;
int main(){
	//freopen("snowboots.in", "r", stdin); freopen("snowboots.out", "w", stdout);
	n = re, b = re;
	for (int i = 0; i < n; i++) s[i] = {re, i};
	for (int i = 0; i < b; i++) q[i] = {re, re, i};
	sort(s, s + n, [](S x, S y){return x.x > y.x;});
	sort(q, q + b, [](Q x, Q y){return x.s > y.s;});
	int ptr = 0;
	for (int i = 0; i < n; i++){
		while(ptr < b && q[ptr].s >= s[i].x)
			ans[q[ptr].i] = mx < q[ptr].d, ptr++;
		auto it = p.lower_bound({s[i].i, 0}), it1 = it;
		if (it != p.begin()) it1--;
		if (it != p.end() && it != p.begin() && (*it1).second == s[i].i - 1 && (*it).first == s[i].i + 1){
			pii np = {(*it1).first, (*it).second};
			mx = max(mx, (*it).second - (*it1).first + 1);
			p.erase(it), p.erase(it1), p.insert(np);
		} else if (it != p.end() && (*it).first == s[i].i + 1){
			pii np = {s[i].i, (*it).second};
			mx = max(mx, (*it).second - s[i].i + 1);
			p.erase(it), p.insert(np);
		} else if (it != p.begin() && (*it1).second == s[i].i - 1){
			pii np = {(*it1).first, s[i].i};
			mx = max(mx, s[i].i - (*it1).first + 1);
			p.erase(it1), p.insert(np);
		} else mx = max(mx, 1), p.insert({s[i].i, s[i].i});
	} 
	for (int i = 0; i < b; i++) printf("%d\n", ans[i]);
}

