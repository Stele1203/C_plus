#include <iostream>
#include <string>
using namespace std;


string pomjeriUdesno(string s){
   ///abcd dabc
    char t= s[s.length()-1];

    for(int i=s.length()-2;i>=0;i--){
        s[i+1]=s[i];
    }
    s[0]=t;
    return s;
}




int main() {
    
    string s;

    getline(cin,s);
    cout<<pomjeriUdesno(s);


    return 0;
}
