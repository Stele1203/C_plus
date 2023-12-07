#include <iostream>
#include <string>
using namespace std;


string ispisi(string S){

    string samo;
    string sugla;

    int n=S.length();

    for(int i=0;i<n;i++){
        char low= tolower(S[i]);
        if(low=='a' || low=='e' || low=='i' || low=='o' || low=='u'){
            samo+=S[i];
        }else{
            sugla+=S[i];
        }
    }
    return samo+sugla;
}




int main() {
    
    string s;

    getline(cin,s);
    cout<<ispisi(s);


    return 0;
}
