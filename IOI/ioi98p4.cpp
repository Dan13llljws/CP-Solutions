#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
const char sp=' ',nl='\n';
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
template<typename T>void read(T &s){s=0;char ch=getchar();ll f=1;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')s=(s<<3)+(s<<1)+ch-48,ch=getchar();s*=f;}
template<typename T, typename...A>void read(T&f,A&...a){read(f);read(a...);}
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define re read()
#define af(x) x.begin(), x.end()
#define pb push_back
const int mod = 1e9 + 7, base = 131, MM = 1e4 + 5;
struct rect{int x1, y1, x2, y2;}rects[MM/2];
struct line{int x, l, r; bool t;};
int n, ans, vis[2 * MM];
vector<line> lines;
bool cmp(line a, line b){
	if (a.x == b.x) return a.t < b.t;
	return a.x < b.x;
}
void sweep(){
	for (line l : lines){
		if (!l.t){
			for (int i = l.l + MM; i < l.r + MM; i++)
				ans += !vis[i], vis[i]++;
		}
		else {
			for (int i = l.l + MM; i < l.r + MM; i++)
				vis[i]--, ans += !vis[i];
		}
	}
}
int main(){
	n = re;
	for (int i = 0; i < n; i++)
		read(rects[i].x1, rects[i].y1, rects[i].x2, rects[i].y2);
	for (int i = 0; i < n; i++){
		lines.pb({rects[i].x1, rects[i].y1, rects[i].y2, 0});
		lines.pb({rects[i].x2, rects[i].y1, rects[i].y2, 1});
	}
	sort(af(lines), cmp);
	sweep(); lines.clear();
	for (int i = 0; i < n; i++){
		lines.pb({rects[i].y1, rects[i].x1, rects[i].x2, 0});
		lines.pb({rects[i].y2, rects[i].x1, rects[i].x2, 1});
	}
	sort(af(lines), cmp);
	sweep();
	pr(ans);
	return 0;
}

