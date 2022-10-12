#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7;
int n, w, t[100005]; ll mxa, mna; multiset<int> s;
int main(){
	n = re, w = re;
	for (int i = 0; i < n; i++) t[i] = re, s.insert(t[i]);
	sort(t, t + n);
	mna = t[n - 1] - min(w, t[0]);
	//mxa += abs(w - t[0]);
	//for (int i = 0, j = n - 1; i < j;){
		////cout << i << ' '<< j << ' ' << mxa << endl;
		//mxa += abs(max(t[j], w) - min(t[i], w));
		//if (t[i + 1] <= w) i++;
		//mxa += abs(max(t[j], w) - min(t[i], w));
		//if (j && t[j - 1] >= 2) j--;
	//}
	int cur = w;
	while(s.size()){
		auto it = s.begin(), it1 = s.end();
		it1--;
		cout << cur << ' '<< *it << ' ' << *it1 << ' ' << mxa << endl;
		if (abs(cur - w) > abs(*it - cur) && abs(cur - w) > abs(*it1 - cur)){
			mxa += abs(cur - w);
			cur = w;
		} else if (abs(*it - cur) > abs(*it1 - cur)){
			 mxa += abs(*it - cur);
			 cur = *it;
			 s.erase(it);
		 } else {
			 mxa += abs(*it1 - cur);
			 cur = *it1;
			 s.erase(it1);
		 }
	 }
	printf("%lld %lld\n", mna, mxa);	
}

