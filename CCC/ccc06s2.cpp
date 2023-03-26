#include <bits/stdc++.h>
using namespace std;
int main()
{
    string plain, cipher, cipher2;
    getline(cin, plain);
    getline(cin, cipher);
    getline(cin, cipher2);
    string eng = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cip = "...........................";
    int pl = plain.length(), cl = cipher2.length();
    for (int i = 0; i < pl; i++){
        cip[eng.find(plain[i])] = cipher[i];
    }
    for (int i = 0; i < cl; i++){
        if (cip.find(cipher2[i]) == -1) cipher2[i] = '.';
        else{
            cipher2[i] = eng[cip.find(cipher2[i])];
        }
    }
    cout <<cipher2;
    return 0;
}