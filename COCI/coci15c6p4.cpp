#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define pb push_back
#define f first
#define s second
const int mod = 1e9;
int n, dp[1<<20]; vector<pii> v;
int main(){
	n = re, dp[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (__gcd(i, j) == 1) v.pb({i - 1, j - 1});
	n--;
	for (pii p : v){
		for (int mask = (1 << n) - 1; mask >= 0; mask--){
			int new_mask = mask | (((1 << p.s) - 1) - ((1 << p.f) - 1));
			dp[new_mask] = (dp[new_mask] + dp[mask]) % mod;
		}
	}
	printf("%d", dp[(1<<n)-1]);
}
