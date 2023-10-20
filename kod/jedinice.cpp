#include <iostream>
using namespace std;

int converse(int a,int k){
    int brojJedinica=0;
    while(a!=0){
        if(a%k==1){
            brojJedinica++;
        }
        a/=k;
    }
    return brojJedinica;
}



void jedinice(int* a, int k, int n,int m){

        for(int i=0;i<m;i++){
            if(converse(a[i],k)>=n){
                cout<<a[i]<<endl;
            }
        }

}


int main() {

    int a[]={1,2,3,4,5,6,17};
    int n= 6;

    jedinice(a,16,2,7);
}
