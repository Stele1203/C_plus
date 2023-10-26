#include <iostream>
#include <climits>
using namespace std;

void scanfMatrix(int** a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //cout<<"a["<<i<<"]["<<j<<"]"<<endl;
            cin >> a[i][j];
        }
    }
}



void magicna(int** a, int n){

    int* b= new int[n];
    int sSum=0;
    int diSum=0;
    int spSum=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=a[i][j];
            if(i==j){
                diSum+=a[i][j];
            }
        }
        spSum+=a[i][n-i-1];
        b[i]=sum;
    }
    int i=0;
    while(i<n){
        if(b[i]!=b[n-1]){
            sSum=-1000;
            break;
        }
        n--;
        i++;
        sSum=b[i];
    }

    cout<<"sSum"<<sSum<<" spSum"<<spSum<<" diSum"<<diSum<<endl;

    if(sSum==spSum && spSum==diSum){
        cout<<"dA";
    }else{
        cout<<"NE";
    }

}

int main() {
    int m, n;

    cin >> n >> m;

    int** a = new int*[n];

    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
    }

    scanfMatrix(a, n, m);

    magicna(a,n);
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}
