#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e6 + 5;
int n, k; pii p[MM]; ll ans = 1e18, sum; priority_queue<int> q;
int main(){
	n = re, k = re;
	for (int i = 0; i < n; i++) p[i] = {re, re};
	sort(p, p + n, [](pii a, pii b){return a.second < b.second;});
	for (int i = 0; i < n; i++){
		q.push(p[i].first), sum += p[i].first;
		if ((int)q.size() > k) sum -= q.top(), q.pop();
		if ((int)q.size() == k) ans = min(ans, sum * p[i].second);
	}
	printf("%lld\n", ans);
}
