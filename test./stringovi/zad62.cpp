#include <iostream>
#include <string>
using namespace std;

bool palindrom(string s){
    int n=s.length();
    for(int i=0;i<n/2;i++){
        if(s[i] != s[n-i-1]){
            return false;
        }
    }
    return true;

}

void najduzi(string s){

    int n=s.length();
    string najduzi;
    int l,d;
    int duzina=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            string tmp= s.substr(i+1,j);
            if(palindrom(tmp) && tmp.length()>duzina){
                najduzi=tmp;
                duzina=tmp.length();
                l=i+1;
                d=j;
            }
        }
    }

    cout<<s.substr(l,d);

}



int main() {
    
    string s,a,b;

    getline(cin,s);
    najduzi(s);


    return 0;
}
