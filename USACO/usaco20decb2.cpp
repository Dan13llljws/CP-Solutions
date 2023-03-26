#include <bits/stdc++.h>
using namespace std;
int n, a[105], ans;
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++){
			int sum = 0;
			for (int k = i; k <= j; k++) sum += a[k];
			if (sum % (j - i + 1)) continue;
			sum /= j - i + 1;
			for (int k = i; k <= j; k++)
				if (sum == a[k]){ans++; break;}
		}
	printf("%d\n", ans);
}
