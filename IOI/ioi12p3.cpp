#include <bits/stdc++.h>
#include <ext/rope>
using namespace std; using namespace __gnu_cxx;
int t; rope<char> r[1000005];
void Init(){}
void TypeLetter(char L){r[t + 1] = r[t], t++, r[t].push_back(L);}
void UndoCommands(int U){r[t + 1] = r[t - U], t++;}
char GetLetter(int P){return r[t].at(P);}
int main(){}	

