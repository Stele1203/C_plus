#include <iostream>
using namespace std;

int main() {

    int n=3;
    int i=1;
    while(i<=n){
        int j=1;
        while(j <= i){
            cout <<"*";
            j++;
        }
        cout<<endl;
        i++;
    }


    while(n >=1){
        int j=n-1;
        while(j >= 1){
            cout << "*";
            j--;
        }
        cout<<endl;
        n--;
    }
    return 0;
}
