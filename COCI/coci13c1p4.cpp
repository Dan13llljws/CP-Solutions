#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 3e5 + 5;
int n, k, c[MM]; pii p[MM]; ll ans; priority_queue<int> q;
int main(){
	n = re, k = re;
	for (int i = 0; i < n; i++) p[i] = {re, re};
	for (int i = 0; i < k; i++) c[i] = re;
	sort(p, p + n); sort(c, c + k);
	int ptr = 0;
	for (int i = 0; i < k; i++){
		while(ptr < n && p[ptr].first <= c[i]) q.push(p[ptr++].second);
		if (q.size()) ans += q.top(), q.pop();
	}
	printf("%lld\n", ans);
}
