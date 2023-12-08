#include <iostream>
#include <string>
using namespace std;

void glas(string s){
    string samo;
    string sugla;

    int n=s.length();

    for(int i=0;i<n;i++){
        char a=tolower(s[i]);
        if(a=='a' || a=='i' || a=='e' || a=='o' || a=='u'){
            samo+=s[i];
        }else{
            sugla+=s[i];
        }
    }
    cout<<samo+sugla;
}

 void glasv2(string s){

    int n=s.length();

    for(int i=0;i<n;i++){
        char a=tolower(s[i]);
        if(a=='a' || a=='i' || a=='e' || a=='o' || a=='u'){
            continue;
        }
        for(int j=i+1;j<n;j++){
            char b=tolower(s[j]);
            if(b=='a' || b=='i' || b=='e' || b=='o' || b=='u'){
                char tmp=s[i];
                s[i]=s[j];
                s[j]=tmp;
                break;
            }
        }

    }
    cout<<s;


}


int main() {
    
    string s;

    getline(cin,s);
    glasv2(s);


    return 0;
}
