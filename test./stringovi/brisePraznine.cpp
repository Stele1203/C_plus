#include <iostream>
#include <string>
using namespace std;


string izbaciPraznine(string s){
    string r;
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i] != ' ' && s[i] != '\n' && s[i] != '\t' ){
            r+=s[i];
        }
    }
    return r;
}



int main() {
    
    string s;

    getline(cin,s);
    cout<<izbaciPraznine(s);


    return 0;
}
