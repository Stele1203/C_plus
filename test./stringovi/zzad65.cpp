#include <iostream>
#include <string>
using namespace std;

string reverse(string s) {
    string novi;
    int n = s.length();
    novi.resize(n);

    for (int i = 0; i < s.length(); i++) {
        novi[n - i - 1] = s[i];
    }
    return novi;
}

string obrni(string s){

    int n=s.length();
    int l=0;
    int d;
    int brojac=0;
    for(int i=0;i<n;i++){
        //cout<<i<<endl;
        if(s[i]==' ' || s[i]=='\n' || s[i]=='\t' || s[i]=='\0'){
            string sub=s.substr(l, brojac);
            s.replace(l,brojac, reverse(sub));
            l=i+1;
            brojac=0;
            continue;
        }else if(i==n-1){
            string sub=s.substr(l,n-l);
            s.replace(l,n-l, reverse(sub));
        }
        brojac++;
    }
    cout<<s;

}


int main() {
    string s1,s2;
    getline(cin,s1);
    obrni(s1);


    return 0;
}
