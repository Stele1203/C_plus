#include <iostream>
#include <cmath>
using namespace std;


void suma(int* a, int n){

    for(int i=0;i<n;i++){
        int suma_prije=0;
        int suma_posle=0;
        if(i>0){

            for(int j=0; j<i;j++){
                suma_prije+=a[j];
            }

        }

        if(i<n-1){
            for(int j=i+1;j<n;j++){
                suma_posle+=a[j];
            }
        }

        if(suma_posle==suma_prije){
            cout<<i<<endl;
        }


    }

}



int main() {
    int n;

    cin>>n;

    int* a = new int[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    suma(a,n);

    return 0;
}
