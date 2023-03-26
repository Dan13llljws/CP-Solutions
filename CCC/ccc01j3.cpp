#include <bits/stdc++.h>
using namespace std;
vector<char> v[4]; int p[4], cur; char c;
int main(){
	while(1){
		c = getchar();
		if (c == '\n') break;
		if (c == 'C') cur = 0;
		else if (c == 'D') cur = 1;
		else if (c == 'H') cur = 2;
		else if (c == 'S') cur = 3;
		else {
			v[cur].push_back(c);
			if (c == 'A') p[cur] += 4;
			else if (c == 'K') p[cur] += 3;
			else if (c == 'Q') p[cur] += 2;
			else if (c == 'J') p[cur]++;
		}
	}
	puts("Cards Dealt\t\tPoints");
	for (int i = 0; i < 4; i++){
		if (!(int)v[i].size()) p[i] += 3;
		else if ((int)v[i].size() == 1) p[i] += 2;
		else if ((int)v[i].size() == 2) p[i]++;
		if (i == 0) printf("Clubs ");
		else if (i == 1) printf("Diamonds ");
		else if (i == 2) printf("Hearts ");
		else if (i == 3) printf("Spades ");
		for (char x : v[i]) printf("%c ", x);
		printf("\t%d\n", p[i]);
	}
	printf("\t\tTotal %d", p[0] + p[1] + p[2] + p[3]);
}
