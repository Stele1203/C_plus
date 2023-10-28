#include <iostream>
#include <cmath>
using namespace std;


    bool djeljiv(int n){

        int n_tmp=n;

        while(n_tmp !=0){
            int cif= n_tmp%10;
            n_tmp=n_tmp/10;

            if(n%cif != 0){
                return false;
            }
        }
        return true;





    }

int main() {
    int n;

    cin>>n;


    if(djeljiv(n)){
        cout<<"da";
    }else{
        cout<<"ne";
    }

    return 0;
}
