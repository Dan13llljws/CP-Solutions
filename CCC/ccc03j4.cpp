#include <bits/stdc++.h>
using namespace std;
string vowels = "aeiou";
string lastSlb(string str){
    for (int i = str.length() - 1; i >= 0; i--)
        for (int j = 0; j < 5; j++){
            if (str[i] < 97 && str[i] != 32) str[i] += 32;
            if (str[i] == vowels[j]) return str.substr(i,str.length() - i + 1);
            else if (str[i] == ' ') return str.substr(i,str.length() - i + 1);
            else if (i == 0) return str;
        }
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int nVerse; cin >>nVerse; cin.ignore();
    for (int i = 0; i < nVerse; i++){
        string lines[4], lastS[4];
        for (int j = 0; j < 4; j++) getline (cin, lines[j]);
        lastS [0] = lastSlb(lines[0]);
        lastS [1] = lastSlb(lines[1]);
        lastS [2] = lastSlb(lines[2]);
        lastS [3] = lastSlb(lines[3]);
        if (lastS[0] == lastS[1] && lastS[1] == lastS[2] && lastS[2] == lastS[3]) cout << "perfect"<<endl;
        else if (lastS[0] == lastS[1] && lastS[2] == lastS[3]) cout << "even"<<endl;
        else if (lastS[0] == lastS[2] && lastS[1] == lastS[3]) cout << "cross"<<endl;
        else if (lastS[0] == lastS[3] && lastS[1] == lastS[2]) cout << "shell"<<endl;
        else cout << "free"<<endl;
    }
}
