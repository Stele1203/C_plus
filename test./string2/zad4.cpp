#include <iostream>
#include <string>
using namespace std;

void umetniSlovo(string& s){

    for(int i=0;i<s.length();i++){
        if(isupper(s[i])){
            char c=tolower(s[i]);
            s.insert(i+1,1,c);
            i++;
        }
    }
}
int main() {
    string s1;
    getline(cin, s1);


    umetniSlovo(s1);
    cout<<s1;


   /// cout << s1;

    return 0;
}
