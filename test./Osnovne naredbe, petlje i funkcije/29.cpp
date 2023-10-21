#include <iostream>
using namespace std;


void zameniMesta(int* a,int n){


    int lijevo=0;
    int desno=n-1;

    while(lijevo<desno){

        if(a[lijevo]%2==0){
            lijevo++;
        }else{
            int tmp=a[lijevo];
            a[lijevo]=a[desno];
            a[desno]=tmp;
            desno--;
        }
    }

}




int main() {

  int n;
  cin>>n;

  int a[]={1,2,3,4,5,6};
    zameniMesta(a,n);



    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}
