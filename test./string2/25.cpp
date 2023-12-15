#include <iostream>
#include <string>
using namespace std;
//. Napisati program koji za data dva stringa S i T provjerava da li su jednaki kada se 
//otkucaju na tastaturi. Karakter ‘#’ ima specijalno značenje i predstavlja pritisak 
//backspace dugmeta na tastaturi (brisanje karaktera ispred kursora). 
//Ulaz: U prvom redu ulaza dat je string S. U drugom redu ulaza dat je string T. 
//Izlaz: U jedinom redu izlaza odštampati “DA” ukoliko su dva stringa jednaki, a “NE” u 
//suprotnom. Primjeri:


void sortString(string& s){
    for(int i=0;i<s.length();i++){
        for(int j=i+1;j<s.length();j++){
            if(s[i]>s[j]){
                char tmp=s[i];
                s[i]=s[j];
                s[j]=tmp;
            }
        }
    }
}


void brisi(string& s){
    int n=s.length()-1;
    int brojac;
    for(int i=0;i<=n;i++){

        if(s[i]=='#'){
            s.erase(i,1);
            i--;
            brojac++;
        }else{
            int j=i-1;
            while(brojac>0){
                if(isalpha(s[j])){
                    s.erase(j,1);
                    j--;
                    i--;
                }
                brojac--;
            }
        }

    }
}


bool uporedi(string s1,string s2){
    brisi(s1);
    brisi(s2);
    sortString(s1);
    sortString(s2);
    if(s1.length() != s2.length()){
        return false;
    }

    for(int i=0;i<s1.length();i++){
        if(s1[i] != s2[i]){
            return false;
        }
    }
    return true;
}

int main() {

    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    //cout<<s2;
    if(uporedi(s1,s2)){
        cout<<"da";
    }else{
        cout<<"ne";
    }
    brisi(s1);
    cout<<endl<<s1;
    brisi(s2);
    cout<<endl<<s2;
    //sortString(s2);
   // cout<<endl<<s2<<endl;

    return 0;
}
