#include <iostream>
using namespace std;


int max(int a, int b){
    if(a>=b){
        return a;
    }else{
        return b;
    }
}

void oduzmi(int* a,int* b,int n,int m){
    int k = max(n, m) + 1;
    int *c = new int[k];

    int i=n-1;
    int j=m-1;
    int d=k-1;
    int ostatak=0;

    while(i>=0 && j>=0){
        int sum=0;
        if(a[i]<b[j] && a[i-1]>0){
            sum=a[i]+10-b[j];
            a[i-1]-=1;
        }else{
            sum=a[i]-b[j];
        }
        c[d]=sum;
        i--;
        j--;
        d--;
    }

    while(i>=0){
        c[d]=a[i];
        d--;
        i--;
    }

    while(j>=0){
        c[d]=b[j];
        j--;
        d--;
    }

    for(int i=0;i<k;i++){
        cout<<c[i]<<" ";
    }

}



void saberi(int* a,int* b, int n,int m) {
    int k = max(n, m) + 1;
    int *c = new int[k];

    int i = n - 1;
    int j = m - 1;
    int d = k - 1;
    int ostatk = 0;
    while (i >= 0 && j >= 0) {
        int sum = a[i] + b[j] + ostatk;
        if (sum > 9) {
            ostatk = sum / 10;
            sum = sum % 10;
        } else {
            ostatk = 0;
        }
        c[d] = sum;
        d--;
        i--;
        j--;

    }

    while (i >= 0) {
        int sum = a[i] + ostatk;
        if (sum > 9) {
            ostatk = sum / 10;
            sum = sum % 10;
        } else {
            ostatk = 0;
        }
        c[d] = sum;
        d--;
        i--;
    }
    while (j >= 0) {
        int sum = b[j] + ostatk;
        if (sum > 9) {
            ostatk = sum / 10;
            sum = sum % 10;
        } else {
            ostatk = 0;
        }
        c[d] = sum;
        d--;
        j--;
    }

    if(ostatk>0){
        c[d]=ostatk;
    }

    while(d>=0){
        c[d]=0;
        d--;
    }

    for(int i=0;i<k;i++){
        cout<<c[i]<<" ";
    }

}





int main() {

    int a[]={3,3,1,2,3,4,9};
    int b[]={2,2,9,9,9,5};


   // saberi(a,b,5,6);

    oduzmi(a,b,7,6);


    return 0;
}
