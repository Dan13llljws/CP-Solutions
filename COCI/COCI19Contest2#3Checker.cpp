#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> pii;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define af(x) x.begin(), x.end()
#define f first
#define s second
const int mod = 1e9 + 7, MM = 2e5 + 5;
int t, n, nxt[MM], clr[MM]; char s[MM]; vector<pii> v;
bool cmp(pii a, pii b){return (a.s.s - a.s.f + n) % n < (b.s.s - b.s.f + n) % n;}
int main(){
	re; n = re; scanf("%s", s);
	for (int i = 1; i < n; i++) nxt[i] = i + 1, clr[i] = s[i - 1] - '0';
	clr[n] = s[n - 1] - '0', nxt[n] = 1;
	for (int i = 0; i < n - 3; i++){
		int x = re, y = re, z = re;
		v.push_back({z, {x, y}}), v.push_back({z, {y, x}});
	}
	sort(af(v), cmp);
	for (int i = 0; i < n - 3; i++){
		int a = v[i].s.f, b = nxt[a], c = v[i].s.s;
		if (nxt[b] != c) return 0 * puts("neispravna triangulacija");
		if (clr[a] == clr[b] || clr[b] == v[i].f || clr[a] == v[i].f) return 0 * puts("neispravno bojenje");
		nxt[a] = c, clr[a] = v[i].f;
	}
	puts("tocno");
}

