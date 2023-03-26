#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 5e4 + 5, b1 = 131, b2 = 13331, mod = 1e9 + 7;
int n, ans, a[5]; unordered_map<ll,int> mp;
int hsh(vector<int> &v, int b){
	int ret = 0;
	for (int x : v) ret = (1LL * ret * b + x) % mod;
	return ret;
}
ll comb(vector<int> &v){return 1LL * hsh(v, b1) << 32 | hsh(v, b2);}
int main(){
	//freopen("cowpatibility.in", "r", stdin); freopen("cowpatibility.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 5; j++) scanf("%d", a + j);
		sort(a, a + 5);
		int cnt = 0;
		for (int mask = 0; mask < 32; mask++){
			vector<int> v; 
			for (int j = 0; j < 5; j++)
				if (mask >> j & 1) v.push_back(a[j]);
			ll h = comb(v);
			if (v.size() & 1) cnt -= mp[h];
			else cnt += mp[h];
			mp[h]++;
		}
		ans += cnt;
	}
	printf("%d\n", ans);;
}
