#include <iostream>
#include <string>
using namespace std;

void test(string s1, string s2){
    int poklapanje;
    int n=s1.length();
    for (int i = 0; i < s1.length();) {
        bool found = false;
        for (int j = 0; j < s2.length(); j++) {
            if (s1[i] == s2[j]) {
                s1.erase(i, 1);
                s2.erase(j, 1);
                poklapanje++;
                found = true;
                break;
            }
        }
        if (!found) {
            i++;
        }
    }
    if(poklapanje==n){
        cout<<"da";
    }else{
        cout<<"ne";
    }
}

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    test(s1, s2);

    return 0;
}
