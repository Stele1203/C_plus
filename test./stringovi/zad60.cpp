#include <iostream>
#include <string>
using namespace std;

string zamijeni(string s,string str1,string str2){

    int n=s.length();
    int k=str1.length();

    for(int i=0;i<n-k;i++){
        string subS1=s.substr(i+1,k);
        if(subS1==str1){
            s.replace(i+1,k,str2);
        }
    }
    return s;
}


int main() {
    
    string s,a,b;

    getline(cin,s);
    getline(cin,a);
    getline(cin,b);
    cout<<zamijeni(s,a,b);


    return 0;
}
