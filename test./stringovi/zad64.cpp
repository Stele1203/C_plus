#include <iostream>
#include <string>
using namespace std;

void sortiraj_string(string &s) {
    int n = s.length();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] > s[j]) {
                char tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
        }
    }
}

bool anagram(string s1,string s2){
    int n=s1.length();
    int m=s2.length();
    if(m != n){
        return false;
    }
    sortiraj_string(s1);
    sortiraj_string(s2);
    for(int i=0;i<n;i++){
        if(s1[i] != s2[i]){
            return false;
        }
    }
    return true;
}


int main() {
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    if(anagram(s1,s2)){
        cout<<"jeste";
    }else{
        cout<<"nije";
    }

    return 0;
}
