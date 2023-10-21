#include <iostream>
using namespace std;

bool duplikati(int* a, int n){
    bool duplikati= false;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]){
                duplikati=true;
                return duplikati;
            }
        }
    }
    return duplikati;

}




int main() {

  int etc[]={5,4,4,2,3};



  if(duplikati(etc,5)){
      cout<<"Ima duplikata";
  }else{
      cout<<"Nema duplikata";
  }

    return 0;
}
