#include <bits/stdc++.h>
using namespace std;
int K, N; deque<string> q[26];
int main(){
	cin >> K >> N;
	for (int i = 0; i < K; i++){
		string s; cin >> s;
		q[s[0] - 'a'].push_back(s);
	}
	for (int i = 0; i < 26; i++) sort(q[i].begin(), q[i].end());
	for (int i = 0; i < N; i++){
		char c; cin >> c; c -= 'a';
		cout << q[c].front() << endl;
		q[c].push_back(q[c].front()); q[c].pop_front();
	}
	return 0;
}
