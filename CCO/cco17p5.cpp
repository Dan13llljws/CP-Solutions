#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int MM = 2e5 + 5;
int n, lft, cnt, ans; vector<int> f[MM]; priority_queue<int> q;
int main(){;
	lft = n = re;
	for (int i = 0; i < n; i++){
		int a = re, b = re;
		f[a].push_back(b);
	}
	for (int i = n; i >= 0; i--){
		for (int x : f[i]) q.push(-x), lft--;
		while(lft + cnt < i) ans += -q.top(), q.pop(), cnt++;
	} printf("%d\n", ans);
}

