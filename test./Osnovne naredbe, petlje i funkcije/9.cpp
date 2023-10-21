#include <iostream>
using namespace std;

int main() {
    int n=153;
    int tmpN=n;
    int sum;

    while(n != 0){
        int tmp=n%10;
        sum=sum+(tmp*tmp*tmp);
        n/=10;
    }
    cout<<sum<<endl;
    if(sum==tmpN){
        cout<<"Jeste";
    }else{
        cout<<"Nije";
    }

    return 0;
}
