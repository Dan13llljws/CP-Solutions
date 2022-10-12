#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 2e5 + 5;
int n, m, k, a[MM], b[MM], idx[MM], t[MM], q[MM], qq[MM], bit[MM], st[20][MM]; ll ans; vector<int> c;
void update(int x){
	x++;
	for (; x <= k; x += x & -x) bit[x]++;
}
int query(int x){
	int ret = 0; x++;
	for (; x; x -= x & -x) ret += bit[x];
	return ret;
}
int get(int l, int r){
	int j = 31 - __builtin_clz(r - l + 1);
	return max(st[j][l], st[j][r - (1 << j) + 1]);
}
int main(){
	n = re, k = re;
	for (int i = 0; i < n; i++) a[i] = re, b[i] = re;
	for (int i = 0; i < k; i++) t[i] = re, c.push_back(t[i]);
	sort(c.begin(), c.end()); c.resize(m = unique(c.begin(), c.end()) - c.begin());
	for (int i = 0; i < k; i++){
		int tt = lower_bound(c.begin(), c.end(), t[i]) - c.begin();
		st[0][tt] = i;
	}
	for (int i = 1; (1 << i) <= m; i++)
		for (int j = 0; j + (1 << i) <= m; j++)
			st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
	for (int i = 0; i < n; i++){
		int aa = lower_bound(c.begin(), c.end(), min(a[i], b[i])) - c.begin();
		int bb = lower_bound(c.begin(), c.end(), max(a[i], b[i])) - c.begin() - 1;
		idx[i] = aa > bb ? -1 : get(aa, bb);
	}
	for (int i = 0; i < n; i++) q[i] = i;
	for (int i = 0; i <= k; i++) qq[i] = i;
	sort(qq, qq + k, [](int x, int y){return t[x] > t[y];});
	sort(q, q + n, [](int x, int y){return max(a[x], b[x]) > max(a[y], b[y]);});
	int ptr = 0;
	for (int i = 0; i <= k; i++){
		while(ptr < n && max(a[q[ptr]], b[q[ptr]]) > t[qq[i]]){
			int cnt = i - query(idx[q[ptr]]);
			if (idx[q[ptr]] == -1) ans += cnt & 1 ? b[q[ptr]] : a[q[ptr]];
			else ans += (a[q[ptr]] > b[q[ptr]]) ^ (cnt & 1) ? a[q[ptr]] : b[q[ptr]];
			ptr++;
		}
		update(qq[i]);
	}
	printf("%lld\n", ans);
}

