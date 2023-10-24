#include <iostream>
using namespace std;
#include "string"

void printArray(int* a, int n){

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}


void sortArray(int* a, int n){

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((a[i] % 2 == 0) && (a[j] % 2==0)){
                if(a[i]>a[j]){
                    int tmp=a[i];
                    a[i]=a[j];
                    a[j]=tmp;
                }
            }
            if((a[i] % 2 == 1) && (a[j] % 2==1)){
                if(a[i]<a[j]){
                    int tmp=a[i];
                    a[i]=a[j];
                    a[j]=tmp;
                }
            }

        }
    }


}


void transform(int* a, int n){

    int b[n];

    int i=0, j=0;
    int tmpN=n-1;

    while(i<=tmpN){
        b[j]=a[tmpN];
        b[j+1]=a[i];
        i++;
        tmpN--;
        j+=2;
    }

    for(int i=0;i<n;i++){
        a[i]=b[i];
    }
}






int main() {

    int a[]={1, 1, 1, 1, 2, 2, 3,3};


    sortArray(a,8);
    transform(a,8);
    printArray(a,8);

    return 0;
}
