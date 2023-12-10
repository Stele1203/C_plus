#include <iostream>
#include <string>
using namespace std;

void rimske(string s){
    int n=s.length();
    int sum=0;
    for(int i=0;i<n;i++){

        if(s[i]=='M'){
            sum+=1000;
        }else if(s[i]=='D'){
            sum+=500;
        }else if(s[i]=='C' && s[i+1]=='M'){
            sum+=900;
            i++;
        }else if(s[i]=='C' && s[i+1]=='D'){
            sum+=400;
            i++;
        }else if(s[i]=='C'){
            sum+=100;
        }else if(s[i]=='L'){
            sum+=50;
        }else if(s[i]=='X' && s[i]=='L'){
            sum+=40;
            i++;
        }else if(s[i]=='X' && s[i]=='C'){
            sum+=90;
            i++;
        }else if(s[i]=='X'){
            sum+=10;
        }else if(s[i]=='V'){
            sum+=5;
        }else if(s[i]=='I' && s[i+1]=='V'){
            sum+=4;
            i++;
        }else if(s[i]=='I' && s[i+1]=='X'){
            sum+=9;
            i++;
        }else if(s[i]=='I'){
            sum+=1;
        }

    }

    cout<<sum;
}


int main() {
    string s1;
    getline(cin, s1);
    rimske(s1);

    return 0;
}
