#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
int n, psa[MM], white[MM], can[MM][105], pf[MM][105], ok[MM][105], sf[MM][105]; char ans[MM];
int get(int l, int r){return psa[r] - psa[l - 1];}
string solve_puzzle(string s, int k, int c[]){
	n = s.size();
	for (int i = 1; i <= n; i++) psa[i] = psa[i - 1] + (s[i - 1] == '_');
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < k; j++){
			if (i < c[j]) continue;
			if (!j && get(i - c[j] + 1, i) == 0)
				can[i][j] = 1;
			else if (j && get(i - c[j] + 1, i) == 0 && pf[i - c[j] - 1][j - 1])
				can[i][j] = 1;
		}
		for (int j = 0; j < k; j++)
			pf[i][j] |= pf[i - 1][j] | can[i][j];
	}
	sf[n + 1][k] = sf[n + 2][k] = 1;
	for (int i = n; i; i--){
		for (int j = 0; j < k; j++){
			if (n - i + 1 < c[j]) continue;
			if (j == k - 1 && get(i, i + c[j] - 1) == 0)
				ok[i][j] = 1;
			else if (j != k - 1 && get(i, i + c[j] - 1) == 0 && sf[i + c[j] + 1][j + 1])
				ok[i][j] = 1;
		}
		for (int j = 0; j <= k; j++)
			sf[i][j] |= sf[i + 1][j] | ok[i][j];
	}
	memset(psa, 0, sizeof psa);
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < k; j++)
			if (can[i][j] && sf[i + 2][j + 1]){
				psa[i - c[j] + 1]++, psa[i + 1]--;
				if (i - c[j]) white[i - c[j]] = 1;
			}
	}
	int l = 0;
	while(sf[l + 2][0]) white[++l] = 1;
	l = n + 1;
	while(pf[l - 2][k - 1]) white[--l] = 1;
	cout << endl;
	for (int i = 1; i <= n; i++){
		psa[i] += psa[i - 1];
		if (white[i] && psa[i]) ans[i] = '?';
		else if (psa[i]) ans[i] = 'X';
		else ans[i] = '_';
	}
	for (int i = 1; i <= n; i++){
		if (s[i - 1] == 'X') ans[i] = 'X';
		if (s[i - 1] == '_') ans[i] = '_';
	}
	for (int j = 0; j < k; j++){
		for (int i = 1; i <= n; i++) cout << can[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
	for (int j = 0; j < k; j++){
		for (int i = 1; i <= n; i++) cout << ok[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
	for (int j = 0; j < k; j++){
		for (int i = 1; i <= n; i++) cout << pf[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
	for (int j = 0; j < k; j++){
		for (int i = 1; i <= n; i++) cout << sf[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
	for (int i = 1; i <= n; i++) cout << psa[i] << ' ';
	cout << endl;
	for (int i = 1; i <= n; i++) cout << white[i] << ' ';
	cout << endl;
	 puts(ans + 1);
	return ans + 1;
}
int main(){
	int a[] = {3};
	cout << solve_puzzle(".X........", 1, a) << '\n';
}

