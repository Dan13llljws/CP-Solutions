#include <bits/stdc++.h>
using namespace std;
const int MM = 30005, base = 31, mod = 1e9 + 7;
struct Q{int id, w;}qq[MM];
int n, q, tot, t, ans[MM], cnt[MM*30], head[MM*30], to[MM*30], nxt[MM*30]; char s[MM<<1][35], v[MM*30]; unordered_map<int,int> id;
int qry(int i){
	int rt = 0, ret = cnt[rt];
	for (int j = 0; s[i][j]; j++){
		int ch = 0;
		for (int k = head[rt]; k; k = nxt[k])
			if (v[to[k]] == s[i][j]){ch = to[k]; break;}
		if (!ch) break;
		ret += cnt[rt = ch];
	} return ret;
}
int get(int i){
	int hsh = 0;
	for (int j = 0; s[i][j]; j++) hsh = (1LL * hsh * base + s[i][j]) % mod;
	return hsh;
}
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%s", s[i]);
		int hsh = get(i);
		if (!id.count(hsh)) id[hsh] = i;
	} scanf("%d", &q);
	for (int i = 0; i < q; i++){
		scanf("%s", s[i + n]);
		int hsh = get(i + n);
		qq[i].w = id.count(hsh) ? id[hsh] : n, qq[i].id = i;
	} sort(qq, qq + q, [](Q a, Q b){return a.w < b.w;}); int j = 0;
	for (int i = 0; i < n; i++){
		int rt = 0; cnt[rt]++;
		for (int i1 = 0; s[i][i1]; i1++){
			int ch = 0;
			for (int j1 = head[rt]; j1; j1 = nxt[j1])
				if (v[to[j1]] == s[i][i1]){ch = to[j1]; break;}
			if (!ch) nxt[++tot] = head[rt], to[tot] = ++t, head[rt] = tot, v[t] = s[i][i1], ch = t;
			cnt[rt = ch]++;
		}
		while(j < q && qq[j].w == i) ans[qq[j].id] = qry(qq[j].id + n), j++;
	}
	while(j < q) ans[qq[j].id] = qry(qq[j].id + n), j++;
	for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
}
