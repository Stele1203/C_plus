#include <iostream>
using namespace std;

int main() {

    int n=1231;
    int brojac=0;
    while(n != 0){
        int tmp= n%10;
        int k= n/10;
        bool da=true;
        while(k !=0){
            if(tmp == k%10) {
                da=false;
            }
            k /= 10;
        }
        n/=10;
        if(da){
            brojac++;
        }
    }
    cout<<brojac;
    return 0;
}
