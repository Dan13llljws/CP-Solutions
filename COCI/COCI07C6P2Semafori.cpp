#include <iostream>
#include <algorithm>
using namespace std;
struct light{int d, r, g;}l[101];
int n, L, tot;
bool cmp(light a, light b){return a.d < b.d;}
int main(){
	scanf("%d%d", &n, &L);
	for (int i = 1; i <= n; i++) scanf("%d %d %d", &l[i].d, &l[i].r, &l[i].g);
	sort(l + 1, l + n + 1, cmp);
	for (int i = 1; i <= n; i++){
		tot += l[i].d - l[i - 1].d;
		int tmp = tot % (l[i].r + l[i].g);
		if (tmp <= l[i].r) tot += l[i].r - tmp;
	}
	printf("%d", tot + L - l[n].d);
	return 0;
}
