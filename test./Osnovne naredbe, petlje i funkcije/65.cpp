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

void binariMatrix(int** a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                bool isBinary = true;
                if (i > 0) {
                    for (int k = i - 1; k >= 0; k--) {
                        if (k != i && a[k][j] != 0) {
                            isBinary = false;
                            break;
                        }
                    }
                }
                if (j > 0) {
                    for (int k = j - 1; k >= 0; k--) {
                        if (k != j && a[i][k] != 0) {
                            isBinary = false;
                            break;
                        }
                    }
                }
                if (j < m - 1) {
                    for (int k = j + 1; k < m; k++) {
                        if (k != j && a[i][k] != 0) {
                            isBinary = false;
                            break;
                        }
                    }
                }
                if (i < n - 1) {
                    for (int k = i + 1; k < n; k++) {
                        if (k != i && a[k][j] != 0) {
                            isBinary = false;
                            break;
                        }
                    }
                }
                if (isBinary) {
                    cout << i << " " << j << endl;
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int** a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
    }
    scanfMatrix(a, n, m);
    binariMatrix(a, n, m);
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}
