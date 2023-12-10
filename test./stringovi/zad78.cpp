#include <iostream>
#include <string>
using namespace std;

void pojavljivanje(string& s1, string& s2) {
    for (int i = 0; i < s1.length();) {
        bool found = false;
        for (int j = 0; j < s2.length(); j++) {
            if (s1[i] == s2[j]) {
                s1.erase(i, 1);
                s2.erase(j, 1);
                found = true;
                break;
            }
        }
        if (!found) {
            i++;
        }
    }
    cout << s1 + s2;
}

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    pojavljivanje(s1, s2);

    return 0;
}
