#include <bits/stdc++.h>
using namespace std;

int findSample(int n, int confidence[], int host[], int protocol[]) {
	int ans = 0;
	for (int i = n - 1; i > 0; i--) {
		int p = host[i];
		if (protocol[i] == 0) {
			ans += confidence[i];
			confidence[p] = max(0, confidence[p] - confidence[i]);
		} else if (protocol[i] == 1) confidence[p] += confidence[i];
		else confidence[p] = max(confidence[p], confidence[i]);
	}
	return ans + confidence[0];
}