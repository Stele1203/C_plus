#include <iostream>
using namespace std;


void scanfMatrix(int** a, int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
}


void lokalniMax(int ** a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool is_max = true;

            if (i > 0 && a[i][j] < a[i - 1][j]) {
                is_max = false;
            }
            if (j > 0 && a[i][j] < a[i][j - 1]) {
                is_max = false;
            }
            if (i < n - 1 && a[i][j] < a[i + 1][j]) {
                is_max = false;
            }
            if (j < m - 1 && a[i][j] < a[i][j + 1]) {
                is_max = false;
            }

            if (is_max) {
                cout <<"aaa"<<a[i][j] << endl;
            }
        }
    }
}




int main() {

    int m,n;

    cin>>n>>m;

    int** a = new int*[n];

    for(int i=0;i<n;i++){
        a[i]= new int[m];
    }

    scanfMatrix(a,n,m);

    lokalniMax(a,n,m);

    for(int i=0;i<n;i++){
        delete[] a[i];
    }
    delete[] a;
    return 0;
}
