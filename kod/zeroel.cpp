#include <iostream>
using namespace std;

    int zeroEl(int* a,int n){
        int br=0;
        int tmpbr=0;
      //  cout<<n<<endl;
        for(int i=0;i<n;i++){
            if(a[i]%10==0){
                tmpbr++;
                if(i==n-1){
                    br=tmpbr;
                }
            }else if(tmpbr>br){
                br=tmpbr;
                tmpbr=0;
            }else{
                tmpbr=0;
            }
        }
        return br;
    }

int main() {

    int a[]={1,20,3,4,50,60,80};

    int n= sizeof(a)/sizeof(a[0]);
    int x=zeroEl(a,n);
    cout<<x;


    return 0;
}
