#include <iostream>
#include <string>
using namespace std;
//Napisati funkciju bool ciklicno(string s, string t, int k) koja provjerava da li se string t 
//moze dobiti cikličnim pomjeranjem stringa s za k mjesta ulijevo ili udesno
string ciklicno_desno(string s,int k){
    int n=s.length();
    int p=n-k;
    string tmp=s;
    string tmp2;
    for(int i=0;i<n-k;i++){
        s[i+k]=tmp[i];
    }
    tmp2=tmp.substr(p,k);
    s.replace(0,k,tmp2);
    return s;


}

string ciklicno_lijevo(string s,int k){
    int n=s.length()-1;
    string tmp=s;
    string tmp2;
    for(int i=n;i>=k;i--){
        s[i-k]=tmp[i];
    }
    tmp2=tmp.substr(0,k);
    s.replace(n-k+1,2,tmp2);
    return s;
}

bool ciklicno(string s,string t,int k){

    string l= ciklicno_lijevo(t,k);
    string d= ciklicno_desno(t,k);

    if((l==s) || (d==s)){
        return true;
    }else{
        return false;
    }


}

int main() {



    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    if(ciklicno(s1,s2,2)){
        cout<<"da";
    }else{
        cout<<"ne";
    }


    return 0;
}
