#include <iostream>
using namespace std;

void printArray(int* a, int n){

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}


void sortArray(int* a,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }

}


void susedni(int* a,int n){
    for(int i=0;i<n;i=i+2){
        int tmp=a[i];
        a[i]=a[i+1];
        a[i+1]=tmp;
    }
}




int main() {

    int a[]={1,3,9,2,5,4,9};
    //int b[]={2,2,9,9,9,5};


   // saberi(a,b,5,6);

   // oduzmi(a,b,7,6);

    sortArray(a,7);
    susedni(a,7);

    printArray(a,7);

    return 0;
}
