#include <iostream>
using namespace std;

int main() {

    int n,k;

    cout<<"Unesi duzinu niza";
    cin>>n;

    int a[]={1,2,3,4,5,6};

    cout<<"Unesi k";
    cin>>k;

    int brojac=0;
    for(int i=0;i<n;i++){
        if(a[i]>k && a[i] % 2== 0){
            brojac++;
        }
    }
    cout<<endl<<"Broj elemenata je "<<brojac;

    return 0;
}
