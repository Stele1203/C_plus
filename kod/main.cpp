#include <iostream>
using namespace std;

    int minArray(int a, int* b,int n){
        int min=INT_MAX;
        for(int i=0;i<n;i++){
            if(b[i]>a){
                if(min>b[i]){
                    min=b[i];
                }
            }
        }
        return min;

    }

int main() {

    int a[]={1,2,3,4};

    int x=minArray(3,a,4);
    cout<<x;


    return 0;
}
