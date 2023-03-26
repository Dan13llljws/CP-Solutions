#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 150005;
int n, k, ans, dsu[MM];
int Find(int x){return dsu[x] == x ? x : dsu[x] = Find(dsu[x]);}
int main(){
	n = re, k = re; iota(dsu, dsu + 4 + 3 * n, 0);
	while(k--){
		int t = re, x = re, y = re;
		if (x > n || y > n){ans++; continue;}
		x *= 3, y *= 3;
		if (t == 1){
			bool w = 1;
			for (int i = 0; i < 3; i++)
				if (Find(x + i) == Find(y + (i + 1) % 3) || Find(y + i) == Find(x + (i + 1) % 3)) w = 0;
			if (!w){ans++; continue;}
			for (int i = 0; i < 3; i++) dsu[Find(x + i)] = Find(y + i);
		} else {
			bool w = 1;
			for (int i = 0; i < 3; i++)
				if (Find(x + i) == Find(y + i) || Find(y + i) == Find(x + (i + 1) % 3)) w = 0;
			if (!w){ans++; continue;}
			for (int i = 0; i < 3; i++) dsu[Find(x + i)] = Find(y + (i + 1) % 3);
		}
	}
	printf("%d\n", ans);
}

