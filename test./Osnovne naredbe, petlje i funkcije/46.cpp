#include <iostream>
using namespace std;
#include "string"

void printArray(int* a, int n){

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}


void sortArray(int* a,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            //if(a[i]>a[j]){

            string s1= to_string(a[i]);
            string s2= to_string(a[j]);
                if((s1+s2)<(s2+s1)) {

                    int tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                }
            //}
        }
    }

}


string spoji(int* a,int n){
    string sum=" ";
    for(int i=0;i<n;i++){
        sum=sum+ to_string(a[i]);
    }

    return sum;

}




int main() {

    int a[]={3, 30, 34, 5, 9};
    //int b[]={2,2,9,9,9,5};


    // saberi(a,b,5,6);

    // oduzmi(a,b,7,6);

    sortArray(a,5);
    cout<<spoji(a,5);

    //printArray(a,7);

    return 0;
}
