#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
int n, ff, al, ar, f[26]; char s[100005]; double ans = 1e9;
int main(){
	scanf("%d %s", &n, s + 1);
	for (int i = 1; i <= 26; i++){
		int mx = 0, ml = 0, mr = 0; 
		memset(f, 0, sizeof f); ff = 0;
		for (int l = 1, r = 1; l <= n && r <= n; r++){
			f[s[r] - 'a']++;
			if (f[s[r] - 'a'] == 1) ff++;
			while(ff > i){
				f[s[l] - 'a']--;
				if (!f[s[l++] - 'a']) ff--;
			}
			if (ff == i && mx < r - l + 1) mx = r - l + 1, ml = l, mr = r;
		}
		if (mx && 1.0 * i / mx < ans) ans = 1.0 * i / mx, al = ml, ar = mr;
	}
	printf("%d %d\n", al, ar);
}
