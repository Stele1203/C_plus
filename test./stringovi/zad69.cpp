#include <iostream>
#include <string>
using namespace std;




bool prefiks(string s){
    bool slovo=false;
    bool broj=false;
    int n=s.length();
    bool pocetak=false;
    bool kraj=false;
    bool tacke=true;

    if((s[0]>='0' && s[0]<'9') || (s[0]>='a' && s[0]<='z')){
        pocetak= true;
    }
    if((s[n-1]>='0' && s[n-1]<'9') || (s[n-1]>='a' && s[n-1]<='z')){
        kraj= true;
    }
    if(isalpha(s[0])){
        slovo=true;
    }
    if(isalpha(s[n-1])){
        slovo=true;
    }
    if(isdigit(s[0])){
        broj=true;

    }
    if(isdigit(s[n-1])){
        broj=true;
    }




    for(int i=1;i<n-1;i++){

        if(s[i]=='.' && s[i+1]=='.'){
            tacke= false;
        }


        if((s[i]>='a' && s[i]<='z')) {
            slovo=true;
        }

        if (s[i]>='0' && s[i]<='9'){
            broj=true;
        }

        if (!((s[i]=='-' || s[i]=='_' || s[i]=='.') || (s[i]>='0' && s[i]<'9') || ((s[i]>='a' && s[i]<='z')))){
           return false;
        }
    }
    if(slovo && pocetak && kraj && broj && tacke){
        return true;
    }else{
        return false;
    }

}

bool domen(string s){
    int n=s.length();


    if(!(isalpha(s[n-2]) && isalpha(s[n-1]))){
        return false;
    }

    for(int i=0;i<n-2;i++){

        if(s[i]=='.' && s[i+1]=='.'){
            return false;
        }

        if (!((s[i]=='-' || s[i]=='.') || (s[i]>='0' && s[i]<'9') || ((s[i]>='a' && s[i]<='z')))){
            return false;
        }
    }
    return true;

}

void valid_mail(string s){
    int n=s.length();
    bool prefiksP,domenP;
    for(int i=0;i<n;i++){
        if(s[i]=='@'){
            string prefikss=s.substr(0,i);
            prefiksP=prefiks(prefikss);
            string domenn=s.substr(i+1,n-(i+1));
            domenP=domen(domenn);
            cout<<domenn<<endl;
            cout<<prefikss<<endl;

            if(domenP && prefiksP){
                cout<<"validna";
            }else{
                cout<<"nije validna";
            }
        }
    }
}


int main() {
    string s1,s2;
    getline(cin,s1);
    valid_mail(s1);


    return 0;
}
