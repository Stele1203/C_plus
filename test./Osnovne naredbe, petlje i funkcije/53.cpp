#include <iostream>
#include <climits>
using namespace std;

void scanfMatrix(int** a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<"a["<<i<<"]["<<j<<"]"<<endl;
            cin >> a[i][j];
        }
    }
}

void maxKec(int** a, int n, int m) {
    int red;
    int maxSum = INT_MIN;
    int startI,startJ,endN,endM;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int x=i;x<n;x++){
                for(int y=j; y<m;y++){
                    bool one=true;
                    int sum=0;
                    for(int p=i;p<=x;p++){
                        for(int q=j;q<=y;q++){
                            if(a[p][q] != 1){
                                one=false;
                            }else{
                                sum++;
                            }
                        }
                    }

                    if(one && (y-j)==(x-i) && sum>maxSum){
                        maxSum=sum;
                        red=(x-i)+1;
                        startI=i;
                        startJ=j;
                        endN=x;
                        endM=y;
                    }
                }
            }
        }
    }

    cout<<"***************"<<endl;
    cout<<red<<endl;
    cout<<"***************"<<endl;
    for(int i=startI;i<=endN;i++){
        for(int j=startJ;j<=endM;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
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

    maxKec(a, n, m);

    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}
