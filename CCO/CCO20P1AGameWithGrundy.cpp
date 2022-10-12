#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, base = 131, MM = 1e5 + 5;
int N, L, R, Y, tot, cnt, psa[MM]; pii evt[2 * MM];
int main(){
	N = re, L = re, R = re, Y = re;
	evt[tot++] = {L, 0}, evt[tot++] = {R + 1, 0};
	for (int i = 0; i < N; i++){
		int x = re, v = re, h = re;
		int l = x - Y * h / v, r = x + Y * h / v + 1;
		if (Y * h % v == 0) l++, r--;
		evt[tot++] = {l, 1}, evt[tot++] = {r, -1};
	}
	sort(evt, evt + tot);
	for (int i = 0; i < tot - 1; i++){
		cnt += evt[i].second;
		if (evt[i].first < L || evt[i].first > R || evt[i].first == evt[i + 1].first) continue;
		psa[cnt] += evt[i + 1].first - evt[i].first;
	}
	printf("%d\n", psa[0]);
	for (int i = 1; i <= N; i++) psa[i] += psa[i - 1], printf("%d\n", psa[i]);
}
