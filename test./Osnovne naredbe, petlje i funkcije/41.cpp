#include <iostream>
using namespace std;




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

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

}



int main() {

    int a[]={1,3,9,2,5,4,9};
    //int b[]={2,2,9,9,9,5};


   // saberi(a,b,5,6);

   // oduzmi(a,b,7,6);

    sortArray(a,7);
    return 0;
}
