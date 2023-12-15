#include <iostream>
#include <string>
using namespace std;
//. Lower camel case i snake case su konvencije za imenovanje funkcija i promjenljivih
//koje se koriste u programiranju. U lower camel case notaciji prvo slovo identifikatora
//je malo, a prvo slovo svake naredne riječi je veliko (npr. brojMobilnogTelefona,
//izracunajUkupnuSumu). U snake case notaciji su sva slova identifikatora mala, a
//riječi su razdvojene donjim crtama (npr. broj_mobilnog_telefona,
//izracunaj_ukupnu_sumu). Napisati program koji identifikator napisan u Lower camel
//case-u pretvara u identifikator u snake case-u.

void convert(string& s){
    int n=s.length();

    for(int i=0;i<n;i++){
        if(isupper(s[i])){
            s[i]= tolower(s[i]);
            s.insert(i,1,'_');
            i++;
            n++;
        }

    }


}

int main() {
    string s1,s2;
    getline(cin,s1);

    convert(s1);
    //char a=5+'0';
    cout<<s1;


    return 0;
}
