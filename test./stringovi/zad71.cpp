#include <iostream>
#include <string>
using namespace std;

void obrniString(string s){
    int n = s.length();
    int i = 0;
    int j = n - 1;

    while (i < j) {
        if (!isalpha(s[i])) {
            i++;
            continue;
        }
        if (!isalpha(s[j])) {
            j--;
            continue;
        }

        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;

        i++;
        j--;
    }

    cout << s;
}

int main() {
    string s1;
    getline(cin, s1);
    obrniString(s1);

    return 0;
}
