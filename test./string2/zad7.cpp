#include <iostream>
#include <string>
using namespace std;
//Napisati funkciju void umetniCifru(string& s) koja transformiše taj string s tako što
//nakon svake cifre veće od 0 u stringu umetne cifru za jedan manju, a nakon cifre 0
//umetne cifru 9. Na primjer, unijeti string s = "ab2c9#03", funkcija treba da transformiše
//u "ab21c98#0932". 
void umetniCifru(string& s){

    int n=s.length();

    for(int i=0;i<n;i++){
        if(isdigit(s[i])){
            //string tmp=s[i];
            int a= s[i]-'0';
            if(a==9){
                a=0;
            }else{
                a++;
            }
            char b= a+'0';

            s.insert(i+1,1,b);
            i++;
            n++;
        }
    }

}

int main() {



    string s1,s2;
    getline(cin,s1);

    umetniCifru(s1);
    //char a=5+'0';
    cout<<s1;


    return 0;
}
