#include <bits/stdc++.h>
using namespace std;
int main(){
    string ameri, vowels = "aeiouy";
    while (cin >> ameri, ameri != "quit!"){
        bool consonant = true;
        for (int i = 0; i < 6; i++)
            if (ameri[ameri.size() - 3] == vowels[i]) consonant = 0;
        if (consonant && ameri.substr(ameri.size() - 2, 2) == "or" && ameri.size() > 4)
            ameri = ameri.substr(0, ameri.size() - 2) + "our";
        cout << ameri <<endl;
    }
}
