#include <iostream>
#include <cmath>
using namespace std;

void podnizMaxSum(int* a, int n){

    int max=INT_MIN,startI, endN;


    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int q=i; q<j;q++){
                sum+=a[q];
            }
            if(sum>max){
                cout<<sum<<"**************************"<<endl;
                max=sum;
                startI=i;
                endN=j;
            }
        }
    }


    for(int i=startI;i<endN;i++){
        cout<<a[i]<<" ";
    }


}

int main() {
    int n;
    cin >> n;

   int* a= new int[n];

   for(int i=0;i<n;i++){
       cin>>a[i];
   }

    podnizMaxSum(a,n);
    return 0;
}
