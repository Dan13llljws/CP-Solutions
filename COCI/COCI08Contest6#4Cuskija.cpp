#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int MM = 1e4 + 5;
int n, a[MM]; vector<int> v[3];
int main(){
	n = re;
	for (int i = 0, x; i < n; i++) x = re, v[x%3].push_back(x);
	if ((int)v[0].size() > (n + 1) / 2 || (!v[0].size() && v[1].size() && v[2].size())) return 0 * puts("impossible");
	for (int i = 0; i < n - 2 * (int)v[0].size() + 1 && v[1].size(); i++)
		printf("%d ", v[1].back()), v[1].pop_back();
	for (int i = 0; v[0].size() > 1; i++)
		if (v[1].size()) printf("%d %d ", v[0].back(), v[1].back()), v[1].pop_back(), v[0].pop_back();
		else printf("%d %d ", v[0].back(), v[2].back()), v[2].pop_back(), v[0].pop_back();
	if (v[0].size()) printf("%d ", v[0].back());
	while(v[2].size()) printf("%d ", v[2].back()), v[2].pop_back();
	puts("");
}
