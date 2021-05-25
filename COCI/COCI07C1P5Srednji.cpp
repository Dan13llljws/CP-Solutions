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
typedef pair<int, int> pii;
const int MM = 1e5 + 5;
int N, B, a[MM], d[MM], b_pos, ans;
map<int, int> cant_think_of_a_name;
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(N, B);
    for (int i = 0; i < N; i++){
		sc(a[i]);
		if (a[i] == B) b_pos = i;
	}
	int tmp = 0;
	for (int i = b_pos; i >= 0; i--){
		if (a[i] < B) tmp--;
		else if (a[i] > B) tmp++;
		cant_think_of_a_name[tmp]++;
		if (!tmp) ans++;
	}
	tmp = 0;
	for (int i = b_pos + 1; i < N; i++){
		if (a[i] < B) tmp--;
		else if (a[i] > B) tmp++;
		ans += cant_think_of_a_name[-tmp];
	}
	pr(ans);
    return 0;
}

