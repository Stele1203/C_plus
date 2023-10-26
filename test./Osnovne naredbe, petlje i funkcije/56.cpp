#include <iostream>
#include <climits>
using namespace std;

/*void scanfMatrix(int** a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //cout<<"a["<<i<<"]["<<j<<"]"<<endl;
            cin >> a[i][j];
        }
    }
}*/


void printMatrix(int** a, int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }

    }


    void popuniMatricu(int** a,int n) {
        int vrh = 0, dno = n - 1, lijevo = 0, desno = n - 1;
        int broj = 1;
        while(broj<=n*n){
        for (int i = lijevo; i <= desno; i++) {
            a[vrh][i] = broj;
            broj++;
        }
        vrh++;
        for (int i = vrh; i <= dno; i++) {
            a[i][desno] = broj;
            broj++;
        }
        desno--;

        for (int i = desno; i >= lijevo; i--) {
            a[dno][i] = broj;
            broj++;
        }
        dno--;

        for (int i = dno; i >= vrh; i--) {
            a[i][lijevo] = broj;
            broj++;
        }
        lijevo++;

    }
}


int main() {
    int m, n;

    cin >> n >> m;

    int** a = new int*[n];

    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
    }

    //scanfMatrix(a, n, m);

   // magicna(a,n);

    popuniMatricu(a,n);
    printMatrix(a,n);
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}
