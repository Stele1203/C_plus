#include <iostream>
#include <string>
using namespace std;

int prestupna(int godina)
{
    if (godina % 400 == 0)
        return 1;
    else if (godina % 4 == 0 && godina % 100 != 0)
        return 1;
    else
        return 0;
}

void valideDate(string s){
    string tmp=s.substr(0,2);
    int dan= stoi(tmp);
    tmp=s.substr(3,2);
    int mjesec= stoi(tmp);
    tmp=s.substr(6,s.length()-6);
    int godina= stoi(tmp);

    if(((mjesec==1)||(mjesec==3) || (mjesec==5) || (mjesec==7) || (mjesec==8) || (mjesec==10)) && dan==31){
        dan=1;
        mjesec++;
    }else if((mjesec==12) && dan==31){
        dan=1;
        mjesec=1;
        godina++;
    }else if((prestupna(godina)) && dan==29){
        dan=1;
        mjesec++;
    }else if((!prestupna(godina)) && dan==28){
        dan=1;
        mjesec++;
    }else if(((mjesec==4)||(mjesec==6) || (mjesec==9) || (mjesec==11)) && dan==30){
        dan=1;
        mjesec++;
    }else{
        dan++;
    }

    //cout<<dan<<" "<<mjesec<<" "<<godina;
    s= to_string(dan)+"."+ to_string(mjesec)+"."+to_string(godina);
    cout<<s;
}

void sledeciDan(string s){


}


int main() {
    string s1,s2;
    getline(cin,s1);
    valideDate(s1);

    return 0;
}
