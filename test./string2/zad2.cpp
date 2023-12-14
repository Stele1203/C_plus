#include <iostream>
#include <string>
using namespace std;


void toMala(string s){
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]>='A' && s[i]<='Z'){
            s[i]=tolower(s[i]);
        }
    }
    cout<<s;

}


int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    toMala(s1);

    return 0;
}
