#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define nl '\n'
#define mod 3001
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define sz(x) (int)(x.size())
typedef long long ll;
typedef unsigned long long ull;
const int MM = 2e5 + 5, base = 131;
int n, m, cnt[26], psa[MM][26];
char a[MM], b[MM];
ull h[MM], p[MM];
unordered_set<ull> vis;
ull get(int l, int r){
	return h[r] - h[l - 1] * p[r - l + 1];
}
int main(){
	scanf("%s %s", b + 1, a + 1);
	n = strlen(a + 1), m = strlen(b + 1);
	for (int i = 1; i <= n; i++) cnt[b[i] - 'a']++;
	p[0] = 1;
	for (int i = 1; i <= n; i++){
		p[i] = p[i - 1] * base;
		h[i] = h[i - 1] * base + a[i] - 'a';
		psa[i][a[i] - 'a']++;
		for (int j = 0; j < 26; j++) psa[i][j] += psa[i - 1][j];
	}
	for (int l = 1, r = m; r <= n; l++, r++){
		bool flag = 1;
		for (int i = 0; i < 26; i++)
			if (psa[r][i] - psa[l - 1][i] != cnt[i]){flag = 0; break;}
		if (flag) vis.insert(get(l, r));
	}
	pr(sz(vis));
    return 0;
}
