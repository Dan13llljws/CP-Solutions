#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e5 + 5, MN = 1e6 + 5;
int n, k, add, a[MM], b[MM], cnt[MN*2]; ll sum, ans = LLINF;
int main(){
	n = re, k = re;
	for (int i = 0; i < n; i++) a[i] = re;
	for (int i = 0; i < n; i++) b[i] = re - a[i], cnt[b[i] + MN]++;
	sort(b, b + n); 
	int l = 0, r = n - k - 1;
	for (int i = l; i <= r; i++) sum += abs(b[i] + 1e6);
	for (int x = -1e6; x <= 1e6; x++){
		while(r < n - 1 && sum > sum - abs(b[l] - x) + abs(b[r + 1] - x)) sum = sum - abs(b[l++] - x) + abs(b[++r] - x), add--;
		add += cnt[x + MN], sum = sum - (r - l + 1 - add) + add, ans = min(ans, sum);
	}
	printf("%lld\n", ans);
}
