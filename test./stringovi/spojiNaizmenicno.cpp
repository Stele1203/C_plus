#include <iostream>
#include <string>
using namespace std;


string spoji(string s1,string s2){

   string spojen;

   for(int i=0;i<s1.length();i++){
       spojen+=s1[i];
       spojen+=s2[i];
   }
   return spojen;
}




int main() {
    
    string s;
    string b;
    getline(cin,s);
    getline(cin,b);
    cout<<spoji(s,b);


    return 0;
}
