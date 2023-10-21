#include <iostream>
using namespace std;






int main() {

  int etc[]={5,4,6,4,3};

  int ocene[]={7,8,6,9,10};

  int n=5;

  float sum=0,sumEtc=0;


  for(int i=0;i<n;i++){
      sum=sum+(etc[i]*ocene[i]);
      sumEtc+=etc[i];
  }
  sum=sum/sumEtc;

  cout<<sum;

    return 0;
}
