#include <bits/stdc++.h>
using namespace std;
int main(){
	int h, w;
	cin >> h >> w;
	int x, y;
	auto answer = [&](int x, int y) -> void {
		cout << "! " << x << ' ' << y << endl;
		exit(0);
	};
	int m = w / 2;
	cout << "? ";
	for (int i = 0; i < m; i++) cout << ">";
	for (int i = 0; i < h; i++){
		for (int j = m; j < w - 1; j++) cout << ">";
		if (i != h - 1){
			for (int j = m; j < w - 1; j++) cout << "<";
			cout << "v";
		}
	} 
	cout << endl; cin >> x >> y;
	if (x != h - 1) {
		answer(x + 1, m);
	} else if (y == w - 1){
		cout << "? ";
		for (int i = 0; i < m; i++) cout << ">";
		for (int i = 0; i < h; i++){
			for (int j = 1; j < m; j++) cout << "<";
			if (i != h - 1){
				for (int j = 1; j < m; j++) cout << ">";
				cout << "v";
			}
		} cout << "<";
		for (int i = 0; i < h - 1; i++) cout << "^";
		cout << endl; cin >> x >> y;
		if (!x) answer(h - 1, y - 1);
		else answer(x - 1, y);
	} else {
		cout << "? ";
		for (int i = 0; i < y + 1; i++) cout << ">";
		for (int i = 0; i < h; i++) cout << "v";
		cout << endl; cin >> x >> y;
		if (x == h - 1) answer(0, y + 1);
		else answer(x + 1, y);
	}
}
