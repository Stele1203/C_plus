#include <iostream>
using namespace std;

    int oddSegments(int* a,int n) {
        int brojac=0;
        int tmpBrojac=0;

        for(int i=0;i<n;i++){
            if(a[i]%2==1){
                tmpBrojac++;
                if(n-1==i){
                    goto jump;
                }
            }else{
                jump:
                if(tmpBrojac>brojac){
                    brojac=tmpBrojac;
                    tmpBrojac=0;
                }

            }
        }
        return brojac;

    }
int main() {

    int a[]={1,23,3,-4,-50,-60,-80};

    int n= sizeof(a)/sizeof(a[0]);
    int x=oddSegments(a,n);
    cout<<x;


    return 0;
}
