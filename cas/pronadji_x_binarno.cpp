#include <iostream>
using namespace std;

int binarnoPronadjiX(int* a,int n, int x){

    int l=0;
    int r=n-1;

    while(l<=r){
        int m= (r+l)/2;
        if(a[m]==x){
            cout<<"X pronadjeno";
            return 1;
        }else if(x<a[m]){
            r=m-1;
        }else if(x>a[m]){
            l=m+1;
        }
    }

    cout<<"X nije pronadjeno";
    return -1;


}

int main() {

    int b[]={1,2,3,4,5,6,7,8,10};

    binarnoPronadjiX(b,9,11);
    return 0;
}
