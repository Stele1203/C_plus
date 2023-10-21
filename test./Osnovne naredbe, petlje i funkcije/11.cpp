#include <iostream>
#include <cmath>
using namespace std;

int otpornost_Broja(int n,int i){
    int sum=0;
    while(n !=0){
        sum+= n%10;
        n/=10;
    }
    i++;
    if(sum<10 && sum>-1){
        return i;
    }else{
        otpornost_Broja(sum,i);
    }

}

int main() {
    cout<<otpornost_Broja(269,0);

    return 0;
}
