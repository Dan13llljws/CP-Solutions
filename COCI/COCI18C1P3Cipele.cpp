#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e5 + 5;
int n, m, a[MM], b[MM];
bool check(int x){
	int cnt = 0;
	for (int i = 0, j = 0; i < n && j < m;){
		while (abs(a[i] - b[j]) <= x && i < n && j < m) cnt++, i++, j++;
		if (a[i] > b[j]) j++;
		else i++;
	}
	return cnt == min(m, n);
}
int main(){
	n = re, m = re;
	for (int i = 0; i < n; i++) a[i] = re;
	for (int i = 0; i < m; i++) b[i] = re;
	sort(a, a + n); sort(b, b + m);
	int l = 0, r = 1e9;
	while(l < r){
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
}

