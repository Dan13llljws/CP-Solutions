#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e5 + 5;
int k, q; ll a[MM];
int main(){
	k = re;
	for (int i = 1; i <= k; i++) a[i] = re, a[i] ^= a[i - 1];
	q = re;
	while(q--) printf("%lld\n", a[k + 1] ^ a[(re + k) % (k + 1)] ^ a[re % (k + 1)]);
}

