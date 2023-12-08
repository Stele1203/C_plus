#include <iostream>
#include <string>
using namespace std;


string revese_string(string a){
    string b;
    int n=a.length();

    for(int i=n-1;i>=0;i--){
        b+=a[i];
    }
    return b;
}


string saberi(string a,string b){

    string rez;
    int prvi=a.length();
    int drugi=b.length();
    char ostatk='0';
    while(prvi>0 && drugi>0){
        if(a[prvi-1] == '1' && b[drugi-1]== '1' && ostatk == '1'){
            rez+='1';
            ostatk='1';
        }else if(a[prvi-1] == '0' && b[drugi-1]== '0' && ostatk=='0'){
            rez+='0';
            ostatk='0';
        }else if(a[prvi-1] == '1' && b[drugi-1]== '0' && ostatk=='0'){
        rez+='1';
        ostatk='0';
         }else if(a[prvi-1] == '0' && b[drugi-1]== '1' && ostatk=='0'){
        rez+='1';
        ostatk='0';
        }else if(a[prvi-1] == '0' && b[drugi-1]== '0' && ostatk=='1'){
        rez+='1';
        ostatk='0';
        }else if ((a[prvi-1] == '1' && b[drugi-1]== '1' && ostatk=='0') || (a[prvi-1] == '0' && b[drugi-1]== '1' && ostatk=='1')||(a[prvi-1] == '1' && b[drugi-1]== '0' && ostatk=='1')){
            rez+='0';
            ostatk='1';
        }
        prvi--;
        drugi--;
    }

    while (prvi>0){
        if(a[prvi-1]=='1' && ostatk=='1'){
            rez+='0';
            ostatk='1';
        }else{
            rez+='1';
            ostatk='0';
        }
        prvi--;
    }
    while (drugi>0){
        if(a[drugi-1]=='1' && ostatk=='1'){
            rez+='0';
            ostatk='1';
        }else{
            rez+='1';
            ostatk='0';
        }
        drugi--;
    }


    if (ostatk=='1'){
        rez+='1';
    }
    rez= revese_string(rez);
    return rez;


}



int main() {
    
    string s;
    string b;
    getline(cin,s);
    getline(cin,b);
    cout<<saberi(s,b);


    return 0;
}
