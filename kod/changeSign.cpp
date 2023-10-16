#include <iostream>
using namespace std;

    int changeSign(int* a,int n) {
        bool plus=true;
        bool minus= true;
        int brojac=0;

        for(int i=0;i<n;i++){
            if(a[i]>=0 && plus){
                brojac++;
                plus=false;
                minus= true;
            }else if(a[i]<0 && minus){
                plus=true;
                minus= false;
                brojac++;
            }
        }
        return brojac;


    }
int main() {

    int a[]={1,20,3,-4,-50,-60,-80};

    int n= sizeof(a)/sizeof(a[0]);
    int x=changeSign(a,n);
    cout<<x;


    return 0;
}
