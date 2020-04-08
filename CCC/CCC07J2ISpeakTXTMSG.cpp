#include <bits/stdc++.h>
using namespace std;
int main()
{
    string input;
    cin >> input;
    while (input != "TTYL"){
        if (input == "CU") cout << "see you"<<endl;
        else if (input == ":-)") cout << "I'm happy"<<endl;
        else if (input == ":-(") cout << "I'm unhappy"<<endl;
        else if (input == ";-)") cout << "wink"<<endl;
        else if (input == "(~.~)") cout << "sleepy"<<endl;
        else if (input == "TA") cout << "totally awesome"<<endl;
        else if (input == "CCC") cout << "Canadian Computing Competition"<<endl;
        else if (input == "CUZ") cout << "because"<<endl;
        else if (input == "TY") cout << "thank-you"<<endl;
        else if (input == "YW") cout << "you're welcome"<<endl;
        else cout << input <<endl;
        cin >> input;
    }
    cout << "talk to you later";
    return 0;
}