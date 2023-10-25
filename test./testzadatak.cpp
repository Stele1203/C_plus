#include <iostream>
using namespace std;

void sortArray(int* a, int n){

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]>a[i]){
                int tmp;
                tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }

}


void pronadjiDrugiEl(int* a, int n){
    int k;
    for(int i=1;i<n;i++){

        if(a[0]!= a[i]){
            k=a[i];
            break;
        }

    }
    cout<<k;

}



int main() {


    int a[6]={4,8,2,8,5,3};
    sortArray(a,6);
    pronadjiDrugiEl(a,6);
    return 0;
}
