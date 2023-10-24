#include <iostream>
using namespace std;




int main() {

    int redovi,kolone;

    cin>>redovi>>kolone;


    int** matrica=new int*[redovi];

    for(int i=0;i<redovi;i++){
        matrica[i]=new int[kolone];
    }

    int sum=0;
    for(int i=0;i<redovi;i++){
        for(int j=0;j<kolone;j++){
            if(i%2==0 && j%2==1){
                sum+=a[i][j]
            }
        }
    }

    cout<<sum;



    for(int i=0;i<redovi;i++){
        delete[] matrica[i];
    }
    delete[] matrica;
    return 0;
}
