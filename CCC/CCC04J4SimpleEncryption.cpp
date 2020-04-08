#include <bits/stdc++.h>
using namespace std;
int main()
{
    string head;
    cin >> head;
    int hl = head.length();
    string text;
    getline(cin, text);
    getline(cin, text);
    int tl = text.length();
    string ecp = "";
    int s = 0;
    for (int i = 0; i < tl; i++){
        if (text[i] >= 'A' && text[i] <= 'Z'){
            char newEcp =  text[i] + head[s] - 'A';
            if (newEcp > 'Z') newEcp = newEcp - 'Z' + 64;
            ecp += newEcp;
            s++;
            if(s == hl) s = 0;
        }
    }
    cout << ecp <<endl;
    return 0;
}