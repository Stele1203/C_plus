#include <iostream>
using namespace std;

int main() {

   int n=12;
   int sum=0;
   for(int i=1;i<n;i++){
       if((n%i)==0){
           sum+=i;
       }
   }

   if(sum==n){
       cout<<"Broj je savrsnen";
   }else{
       cout<<"Broj nije savrsen";
   }
    return 0;
}
