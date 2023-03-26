#include <bits/stdc++.h>
using namespace std;
int a[7];
int main(){
	for (int i = 0; i < 7; i++) scanf("%d", a + i);
	sort(a, a + 7);
	printf("%d %d %d\n", a[0], a[1], a[6] - a[0] - a[1]);
}
