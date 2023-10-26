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

void maxMatrix(int** a, int n, int m) {
    int maxSum = INT_MIN;
    int startI, startJ, endN, endM;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int x = i; x < n; x++) {
                for (int y = j; y < m; y++) {
                    int sum = 0;

                    for (int q = i; q <= x; q++) {
                        for (int b = j; b <= y; b++) {
                            sum += a[q][b];
                        }
                    }

                        if (sum > maxSum && (x > i) && (y > j)) {
                            maxSum = sum;
                            startI = i;
                            startJ = j;
                            endN = x;
                            endM = y;
                        }

                }
            }
        }
    }
    cout<<endl<<startI<<" "<<startJ<<" "<<endN<<" "<<endM<<endl;
    cout << "****************************" << endl;
    for (int i = startI; i <= endN; i++) {
        for (int j = startJ; j <= endM; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
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

    maxMatrix(a, n, m);
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}
