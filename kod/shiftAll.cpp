#include <iostream>
using namespace std;

    void printArray(int* a, int n){
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
    }


    void shiftLeft(int* a, int n){
        int tmp;
        for(int i=0;i<(n/2);i++){
            tmp= a[i];
            a[i]=a[n-i-1];
            a[n-i-1]=tmp;
        }
        printArray(a,n);
    }
int main() {

    int a[]={1,23,3,-4,-50,-60,-80};

    int n= sizeof(a)/sizeof(a[0]);
    shiftLeft(a,n);


    return 0;
}
