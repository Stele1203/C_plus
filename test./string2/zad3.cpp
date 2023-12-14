#include <iostream>
#include <string>
using namespace std;

void velikaSlova(string& s) {
    int n = s.length();
    for (int i = 0; i <s.length(); i++) {
        if (isupper(s[i]) && isupper(s[i + 1])) {
            s.insert(i+1,"_");
            i++;
            n++;
        }
    }
    cout<<s;
}

int main() {
    string s1;
    getline(cin, s1);


    velikaSlova(s1);
    //cout<<s1;


   /// cout << s1;

    return 0;
}
