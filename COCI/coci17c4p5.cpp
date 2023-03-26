#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e5 + 5;
int n, a[MM]; ll ans = 1e18, bit[4][MM<<1]; vector<int> cmp;
void upd(int i, int x, ll v){
	for (; x <= n * 2; x += x & -x) bit[i][x] += v;
}
ll get(int i, int x){
	ll ret = 0;
	for (; x; x -= x & -x) ret += bit[i][x];
	return ret;
}
int get_idx(ll x){return lower_bound(cmp.begin(), cmp.end(), x) - cmp.begin() + 1;}
ll get_val(int x, int i){
	int j = get_idx(x + 1) - 1;
	return get(i, j);
}
ll get_ans(int x){
	int l = max(x, n - x + 1), r = 1e9 + n;
	while(l < r){
		int mid = (l + r) >> 1;
		if (get_val(mid - x, 0) + get_val(mid + x, 1) > n / 2) r = mid;
		else l = mid + 1;
	}
	ll k1 = get_val(l - x, 0), k2 = get_val(l + x, 1);
	return k1 * (l - x) - 2 * get_val(l - x, 2) + get_val(2e9, 2) - (x - k1 - 1) * (l - x)
		 + k2 * (l + x) - 2 * get_val(l + x, 3) + get_val(2e9, 3) - (n - x + 1 - k2) * (l + x);
}
int main(){
	n = re;
	for (int i = 1; i <= n; i++) a[i] = re, cmp.push_back(a[i] - i), cmp.push_back(a[i] + i);
	sort(cmp.begin(), cmp.end()), cmp.resize(unique(cmp.begin(), cmp.end()) - cmp.begin());
	for (int i = 1; i <= n; i++){
		int tmp = get_idx(a[i] + i);
		upd(1, tmp, 1), upd(3, tmp, a[i] + i);
	}
	for (int i = 1; i <= n; i++){
		ans = min(ans, get_ans(i));
		if (i == n) break;
		int t1 = get_idx(a[i] - i), t2 = get_idx(a[i] + i);
		upd(1, t2, -1), upd(3, t2, -a[i] - i), upd(0, t1, 1), upd(2, t1, a[i] - i);
	}
	printf("%lld\n", ans);
}
