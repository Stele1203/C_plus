#include <iostream>
#include <climits>
using namespace std;

void popuni_matricu3(int** mat, int n) {
    int broj = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = (j + i) % n + 1;
        }
    }
}

int main() {
    int n;
    cin >> n;

    int** matrica = new int*[n];
    for (int i = 0; i < n; i++) {
        matrica[i] = new int[n];
    }

    popuni_matricu3(matrica, n);

    // Ispis matrice
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrica[i][j] << " ";
        }
        cout << endl;
    }

    // Oslobađanje memorije
    for (int i = 0; i < n; i++) {
        delete[] matrica[i];
    }
    delete[] matrica;

    return 0;
}
