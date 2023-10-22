#include <iostream>
using namespace std;

void pronadjiElement(int* a, int n){

    for(int i=0;i<n;i++){
        int lijevo=0;
        int desno=0;
        for(int j=0;j<i;j++){
            lijevo+=a[j];
        }
        for(int j=i+1;j<n;j++){
            desno+=a[j];
        }

        if(lijevo==desno){
            cout<<i<<endl;
        }else{
            cout<<"-1"<<endl;
        }
    }
}





int main() {

    int a[]={0,-3, 5, -4, -2, 3, 1, 0};

    pronadjiElement(a,8);

    return 0;
}
