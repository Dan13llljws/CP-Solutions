#include <bits/stdc++.h>
using namespace std;
int n; string p[100][8]; unordered_map<string,int> dist; queue<string> q;
string yr[12] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 8; j++) cin >> p[i][j];
	q.push("Bessie"); dist["Bessie"] = 0;
	while(q.size()){
		string src = q.front(); q.pop();
		for (int i = 0; i < n; i++){
			if (p[i][7] == src){
				if (dist.count(p[i][0])) continue;
				int cur = dist[src];
				if (p[i][3] == "previous"){while(yr[(cur +1199) % 12] != p[i][4]) cur--; cur--;}
				else{while (yr[(cur + 1201) % 12] != p[i][4]) cur++; cur++;}
				dist[p[i][0]] = cur, q.push(p[i][0]);
			}
		}
	}
	cout << abs(dist["Elsie"]) << '\n';
}
