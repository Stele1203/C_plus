#include <iostream>
#include <string>
using namespace std;

bool isSamoglasnik(char s){
    char c=tolower(s);
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
        return true;
    }
    return false;
}

void umetni(string& s){
    for(int i=0;i<s.length();i++){
        if(isSamoglasnik(s[i]) && isSamoglasnik(s[i+1])){
            s.insert(i+1,1,'_');
            i++;
        }
    }
}


int main() {
    string s1;
    getline(cin, s1);


    umetni(s1);
    cout<<s1;


   /// cout << s1;

    return 0;
}
