#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
int t, st, a[MM], c[MM], pos[MM], vis[MM], L[MM], R[MM]; pair<int,int> s[MM];
int findSwapPairs(int N, int S[], int M, int X[], int Y[], int P[], int Q[]){
	int l = 0, r = M;
	while(l < r){
		int mid = (l + r) >> 1, cnt = 0;
		for (int i = 0; i < N; i++) a[i] = S[i], vis[i] = 0;
		for (int i = 0; i < mid; i++) swap(a[X[i]], a[Y[i]]);
		for (int i = 0; i < N; i++){
			if (vis[i]) continue;
			for (int j = i; !vis[i] || i != j; j = a[j]) vis[j] = 1;
			cnt++;
		}
		if (N - cnt > mid) l = mid + 1;
		else r = mid;
	}
	for (int i = 0; i < N; i++) a[i] = S[i], vis[i] = 0, pos[a[i]] = i;
	for (int i = 0; i < l; i++) swap(a[X[i]], a[Y[i]]);
	for (int i = 0; i < N; i++){
		if (vis[i]) continue; t = 0;
		for (int j = i; !vis[i] || i != j; j = a[j]) vis[j] = 1, c[t++] = a[j];
		for (int j = t - 1; j; j--) s[st++] = {c[j], c[0]};
	}
	for (int i = 0; i < l; i++){
		swap(S[X[i]], S[Y[i]]), swap(pos[S[X[i]]], pos[S[Y[i]]]);
		if (i < st){
			P[i] = pos[s[i].first], Q[i] = pos[s[i].second];
			swap(S[P[i]], S[Q[i]]), swap(pos[S[P[i]]], pos[S[Q[i]]]);
		}
	}
	return l;
}
int main(){}
