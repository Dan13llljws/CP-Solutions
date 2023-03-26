#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
typedef long long ll;
typedef unsigned long long ull;
const int MM = 1e6 + 5, base = 131;
int T; char str[MM];
int main(){
    scanf("%d", &T); 
    while(T--){
		scanf("%s", str + 1); 
		int n = strlen(str + 1), ans = 0;
		ull l = 0, r = 0, p = 1;
		for (int i = 1, j = n; i < j; i++, j--){
			l = l * base + str[i] -  'A';
			r = r + p * (str[j] - 'A');
			p *= base;
			if (l == r) l = 0, r = 0, ans += 2, p = 1;
		}
		if (l || r || n % 2) ans++;
		pr(ans, nl);
	}
    return 0;
}

