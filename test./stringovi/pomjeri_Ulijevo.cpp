#include <iostream>
#include <string>
using namespace std;


string pomjeriUlijevo(string s){

    char t=s[0];
    for(int i=1;i<s.length();i++){
        s[i-1]=s[i];
    }

    s[s.length()-1]=t;
    return s;
}



int main() {
    
    string s;

    getline(cin,s);
    cout<<pomjeriUlijevo(s);


    return 0;
}
