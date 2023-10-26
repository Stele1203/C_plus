#include <iostream>
#include <climits>
using namespace std;

void scanfMatrix(int** a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
}

void printMatrix(int** a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void sortArrayA(int* a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] > a[j]) {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void sortArrayD(int* a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] < a[j]) {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
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

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sortArrayA(a[i], m);
        } else {
            sortArrayD(a[i], m);
        }
    }
    cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&*"<<endl;
    printMatrix(a, n, m);

    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
