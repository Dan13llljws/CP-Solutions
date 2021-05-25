#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
ll n, a[100005], m, sum, ans;
int main(){
	m = re, n = re, a[n] = 1e18;
	for (int i = 0; i < n; i++) sum += a[i] = re;
	sort(a, a + n);
	int tmp = (sum - m) / n, i = 0;
	for (; a[i] < tmp || a[n - (sum - m) % (n - i)] < tmp + 1; i++)
		ans += a[i] * a[i], sum -= a[i], tmp = (sum - m) / (n - i - 1);
	ans += 1LL * tmp * tmp * (n - i - (sum - m) % (n - i)) + 1LL * (tmp + 1) * (tmp + 1) * ((sum - m) % (n - i));
	printf("%lld\n", ans);
}
