#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7;
int pre, ans, nxt[65537], id[65537];
int main(){
	memset(nxt, -1, sizeof nxt), memset(id, -1, sizeof id);
	for (int l = 0, r = 0; ; r++){
		int a = re;
		if (id[a] != -1) l = id[nxt[a]], id[a] = r;
		ans = max(ans, r - l + 1);
	}
	printf("%d\n", ans);
}

