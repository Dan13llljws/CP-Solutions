#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 505, mod = 1e9 + 7, base = 131;
int n, m; ll h[2*MM][MM], p[MM]; char s[MM];
int get(int i, int l, int r){
	return (h[i][r] - h[i][l - 1] * p[r - l + 1] % mod + mod) % mod;
}
int main(){
	freopen("cownomics.in", "r", stdin), freopen("cownomics.out", "w", stdout);
	scanf("%d%d", &n, &m); p[0] = 1;
	for (int i = 1; i <= m; i++) p[i] = p[i - 1] * base % mod;
	for (int i = 0; i < n; i++){
		scanf("%s", s + 1);
		for (int j = 1; j <= m; j++) h[i][j] = (h[i][j - 1] * base + s[j]) % mod;
	}
	for (int i = 0; i < n; i++){
		scanf("%s", s + 1);
		for (int j = 1; j <= m; j++) h[i + n][j] = (h[i + n][j - 1] * base + s[j]) % mod;
	}
	int l = 1, r = m;
	while(l < r){
		int mid = (l + r) >> 1;
		bool f = 0;
		for (int i = 1; i + mid - 1 <= m; i++){
			unordered_set<int> st;
			for (int k = 0; k < n; k++) st.insert(get(k, i, i + mid - 1));
			bool w = 1;
			for (int k = 0; k < n; k++)
				if (st.count(get(k + n, i, i + mid - 1))) w = 0;
			f |= w;
		}
		if (f) r = mid;
		else l = mid + 1;
	} printf("%d\n", l);
}
				
		
