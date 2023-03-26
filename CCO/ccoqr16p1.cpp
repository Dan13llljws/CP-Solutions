#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e5 + 5;
int n, x[MM], y[MM]; ll ans; map<int, vector<int>> xx, yy;
int main(){
	n = re;
	for (int i = 0; i < n; i++){
		x[i] = re, y[i] = re;
		xx[y[i]].push_back(x[i]), yy[x[i]].push_back(y[i]);
	}
	for (auto &v : xx) sort(v.second.begin(), v.second.end());
	for (auto &v : yy) sort(v.second.begin(), v.second.end());
	for (int i = 0; i < n; i++){
		int a = lower_bound(xx[y[i]].begin(), xx[y[i]].end(), x[i]) - xx[y[i]].begin();
		int b = lower_bound(yy[x[i]].begin(), yy[x[i]].end(), y[i]) - yy[x[i]].begin();
		int c = xx[y[i]].size() - a - 1, d = yy[x[i]].size() - b - 1;
		ans += 2LL * a * b * c * d;
	}
	printf("%lld\n", ans);
}

