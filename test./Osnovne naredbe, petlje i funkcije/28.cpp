#include <iostream>
using namespace std;


void duplirajNiz(int* a, int* b,int n){

    int k=0;

    for(int i=0;i<n;i++){
        b[k]=a[i];
        b[k+1]=a[i];
        k+=2;
    }

}




int main() {

  int n;
  cin>>n;

  int a[]={1,2,3,4,5,6};

  int* b= new int[n*2];
    duplirajNiz(a,b,n);


    for(int i=0;i<n*2;i++){
        cout<<b[i]<<" ";
    }

    return 0;
}
