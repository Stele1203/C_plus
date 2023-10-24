#include <iostream>
using namespace std;


void zamijeniKolone(int** a,int n, int m,int r,int k){

    for(int i=0;i<n;i++){
        int tmp=a[i][k];
        a[i][k]=a[i][r];
        a[i][r]=tmp;
    }
}



int main() {

    int redovi,kolone;

    cin>>redovi>>kolone;


    int** matrica=new int*[redovi];

    for(int i=0;i<redovi;i++){
        matrica[i]=new int[kolone];
    }



    for (int i = 0; i < redovi; i++) {
        for (int j = 0; j < kolone; j++) {
            cin >> matrica[i][j];
        }
    }

    zamijeniKolone(matrica,redovi,kolone,1,3);


    for (int i = 0; i < redovi; i++) {
        for (int j = 0; j < kolone; j++) {
            cout << matrica[i][j]<<" ";
        }
        cout<< endl;
    }



    for(int i=0;i<redovi;i++){
        delete[] matrica[i];
    }
    delete[] matrica;
    return 0;
}
