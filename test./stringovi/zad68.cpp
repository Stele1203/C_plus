#include <iostream>
#include <string>
using namespace std;

bool velikoSlovo(string s){
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]>='A' && s[i]<='Z'){
            return true;
        }
    }
    cout<<"TREBA DA IMA MAKAR JEDNO VELIKO SLOVO";
    return false;
}

bool maloSlovo(string s){
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]>='a' && s[i]<='z'){
            return true;
        }
    }
    cout<<"TREBA DA IMA MAKAR JEDNO MALO SLOVO";
    return false;
}

bool znakovi(string s){
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]=='$' || s[i]=='@'|| s[i]=='#'){
            return true;
        }
    }
    cout<<"TREBA DA IMA MAKAR JEDan SPECIJALAN ZNAK";
    return false;
}



bool passIsValid(string s){
    int n=s.length();
    if(n<6){
        cout<<"Treba da ima makar 6 cifara";
        return false;
    }

    if(velikoSlovo(s) && maloSlovo(s) && znakovi(s)){
        return true;
    }
    return false;
}

int main() {
    string s1,s2;
    getline(cin,s1);
    if(passIsValid(s1)){
        cout<<"sifra je ok";
    }else{
        cout<<"ne";
    }


    return 0;
}
