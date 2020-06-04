#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, base = 131, MM = 1e6 + 5;
int n, q, a[5005], cnt[2*MM]; ll psa[5005][5005];
int main(){
	n = re, q = re;
	for (int i = 1; i <= n; i++) a[i] = re;
	for (int i = n; i; i--){
		for (int k = i + 1; k <= n; k++){
			int x = MM - (a[i] + a[k]);
			if (x >= 0 && x < 2*MM) psa[i][k] = cnt[x];
			cnt[a[k] + MM]++;
		}
		for (int k = i + 1; k <= n; k++) cnt[a[k] + MM]--;
	}
	for (int i = n; i; i--)
		for (int j = i + 1; j <= n; j++) 
			psa[i][j] += psa[i + 1][j] + psa[i][j - 1] - psa[i + 1][j - 1];
	while(q--) printf("%lld\n", psa[re][re]);
}

