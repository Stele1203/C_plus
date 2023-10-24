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


int smallSum(int* a, int n){
    int num1=0;
    int num2=0;

    for(int i=0;i<n;i++){
        if(i%2 == 0){
            num1+=a[i];
        }else{
            num2+=a[i];
        }
    }

    int sum=num1+num2;

    return sum;


}


int main() {

    int a[]={1,3,9,2,5,4,9};
    //int b[]={2,2,9,9,9,5};


   // saberi(a,b,5,6);

   // oduzmi(a,b,7,6);

    sortArray(a,7);
    cout<<smallSum(a,7);

    return 0;
}
