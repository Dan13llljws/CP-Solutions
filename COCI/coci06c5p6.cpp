#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define sz(x) (int)(x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MM = 2e5 + 5, base = 131, base2 = 71, mod = 1e9 + 7;
int L, n;
char str[MM];
ll p[MM], p2[MM], h[MM], h2[MM];
ll get(ll h[], ll p[], int l, int r){
	return (h[r] - (h[l - 1] * p[r - l + 1]) % mod + mod) % mod;
}
ll combine(int l, int r){
    return get(h, p, l, r) << 32 | get(h2, p2, l, r);
}
bool check(int k){
	if (!k) return 1;
	gp_hash_table<ll, null_type> vis;
	for (int i = 1; i <= n - k + 1; i++){
		ll tmp = combine(i, i + k - 1);
		if (vis.find(tmp) != vis.end()) return 1;
		vis.insert(tmp);
	}
	return 0;
}
int main(){
	//freopen("", "r", stdin); freopen("", "w", stdout);
	scanf("%d", &L); p[0] = p2[0] = 1;
	scanf("%s", str + 1);
	n = strlen(str + 1);
	for (int i = 1; i <= n; i++){ 
		p[i] = (p[i - 1] * base) % mod;
		p2[i] = (p2[i - 1] * base2) % mod;
		h[i] = (h[i - 1] * base + str[i] - 'a') % mod;
		h2[i] = (h2[i - 1] * base2 + str[i] - 'a') % mod;
	} 
	int l = 0, r = n;
	while(l < r){
		int mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d", l);
	return 0;
}
