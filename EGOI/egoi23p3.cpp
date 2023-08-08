#include <bits/stdc++.h>
using namespace std;
int main(){
	int h, w;
	cin >> h >> w;
	int x, y;
	auto answer = [&](int x, int y) -> void {
		cout << "! " << x << ' ' << y << endl;
	};
	auto ask = [&](string &s) -> void {
		cout << "? " << s << endl;
		cin >> x >> y;
	};
	int m = w / 2;
	string s(m, '>');
	for (int i = 0; i < h; i++){
		s += string(w - m - 1, '>');
		if (i != h - 1) s += string(w - m - 1, '<') + "v";
	} ask(s);
	if (x != h - 1) answer(x + 1, m); 
	else if (y == w - 1){
		s = string(m, '>');
		for (int i = 0; i < h; i++){
			s += string(m - 1, '<');
			if (i != h - 1) s += string(m - 1, '>') + "v";
		} s += "<" + string(h - 1, '^');
		ask(s);
		if (!x) answer(h - 1, y - 1);
		else answer(x - 1, y);
	} else {
		s = string(y + 1, '>') + string(h, 'v');
		ask(s);
		if (x == h - 1) answer(0, y + 1);
		else answer(x + 1, y);
	}
}
