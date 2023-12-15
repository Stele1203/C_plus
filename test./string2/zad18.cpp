#include <iostream>
#include <string>
using namespace std;
// Napisati program koji učitava string koji predstavlja naziv Excel kolone. Program
//treba da odštampa redni broj unsene kolone. Na primjer: “A” → 1, “B” → 2, “C” →
//2,…, “Z” → 26, “AA” → 27, “AB” → 28, itd. 
//65 90
void kolone(string s){
    int n=s.length();
    int sum=0;
    for(int i=0;i<n;i++){
        int a=s[i]-64;
        sum+=a;
        if(i>0){
            sum+=26-1;
        }
    }
    cout<<sum;

}


int main() {
    string s1,s2;
    getline(cin,s1);
    kolone(s1);
    ///char a='A';
   // int b=a;
   // cout<<b;

    //char a=5+'0';
    //cout<<s1;


    return 0;
}
