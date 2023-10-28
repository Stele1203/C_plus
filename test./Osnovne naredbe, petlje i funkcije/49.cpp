//. Napisati funkciju bool simetricna(int** mat, int m, int n) koja provjerava da li je data 
//kvadratna matrica simetrična u odnosu na glavnu dijagonalu. 
#include <iostream>
#include <cmath>
using namespace std;


void scanfA(int** a, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
}


bool simetricna(int** a, int n){


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] != a[j][i]){
                return false;
            }
        }
    }
    return true;


}

int main() {
    int n;
    cin >> n;

   int** a = new int*[n];

   for(int i=0;i<n;i++){
       a[i]= new int[n];
   }
    scanfA(a,n);

    if(simetricna(a,n)){
        cout<<"da";
    }else{
        cout<<"ne";
    }



   for(int i=0;i<n;i++){
       delete[] a[i];
   }

   delete a;


    return 0;
}
