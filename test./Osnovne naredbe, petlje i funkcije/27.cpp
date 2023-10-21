#include <iostream>
using namespace std;
#include <vector>
int prebraojParne(int* a,int n){
    int brojac=0;
    for(int i=0;i<n;i++){
        if(a[i] % 2== 0){
            brojac++;
        }
    }

    return brojac;

}


void novi_Nizovi(int* a, int* b, int* c,int n,int parni,int neprani){

    int p=0;
    int ne=0;
    for(int i=0;i<n;i++){
        if(a[i]%2==0){
           b[p]=a[i];
           p++;
        }else{
            c[ne]=a[i];
            ne++;
        }
    }


}


void printArray(int* a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}


int main() {

    int n=6;

    int a[]={1,2,3,4,5,6};
    int parni=prebraojParne(a,6);
    int neparni= n-parni;
    int* c= new int[neparni];
    int* b= new int[parni];

    novi_Nizovi(a,b,c,n,parni,neparni);


    printArray(b,parni);
    printArray(c,neparni);


    return 0;
}
