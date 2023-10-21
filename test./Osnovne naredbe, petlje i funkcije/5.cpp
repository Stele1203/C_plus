#include <iostream>
using namespace std;

int main() {

    int n=1231323;
    int broj;
    int brojac=0;
    while(n != 0){
        int tmp= n%10;
        int k= n/10;
        int tmp_brojac=0;
        while(k !=0){
            if(tmp == k%10) {
                tmp_brojac++;
            }
            k /= 10;
        }
        n/=10;
        if(tmp_brojac>brojac){
            brojac=tmp_brojac;
            tmp_brojac=0;
            broj=tmp;
        }
    }
    cout<<broj;
    return 0;
}
