#include <iostream>
#include <string>
using namespace std;

bool pristustvo(string s){
    int n = s.length();
    int z = 0;
    int o = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == 'P'){
            z = 0;
            o = 0;
        } else if(s[i] == 'Z'){
            z++;
            o=0;
        } else if(s[i] == 'O'){
            o++;
            z=0;
        }

        if(o >= 3 || z >= 4){
            return false;
        }
    }

    return true;
}

int main() {
    string s1;
    getline(cin, s1);

    if(pristustvo(s1)){
        cout << "Dobija poene";
    } else {
        cout << "Ne dobija";
    }

    return 0;
}
