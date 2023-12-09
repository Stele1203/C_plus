#include <iostream>
#include <string>
using namespace std;

bool jesteSamogslanik(char s){

    if(s=='a' || s=='i' || s=='e' || s=='o' || s=='u'){
        return true;
    }
    return false;

}

void obrniSamo(string s){

    int i=0;
    int j=s.length()-1;

    while(i<j){
        char prvi=tolower(s[i]);
        char drug=tolower(s[j]);
        prvi:
        if(!jesteSamogslanik(prvi)){
            i++;
            prvi=tolower(s[i]);
            goto prvi;
        }
        drugi:
        if(!jesteSamogslanik(drug)){
            j--;
            drug=tolower(s[j]);
            goto drugi;
        }

        char tmp=s[i];
        s[i]=s[j];
        s[j]=tmp;
        j--;
        i++;

    }
    cout<<s;

}

int main() {
    string s1;
    getline(cin, s1);
    obrniSamo(s1);

    return 0;
}
