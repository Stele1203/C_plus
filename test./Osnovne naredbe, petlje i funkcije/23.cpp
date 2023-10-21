#include <iostream>
using namespace std;

int main() {
    int broj;
    cout << "Unesite prirodan broj: ";
    cin >> broj;

    int originalni_broj = broj;
    bool djeljiv_svakom_cifrom = true;

    while (broj > 0) {
        int cifra = broj % 10;
        if (cifra == 0 || originalni_broj % cifra != 0) {
            djeljiv_svakom_cifrom = false;
            break;
        }
        broj /= 10;
    }

    if (djeljiv_svakom_cifrom) {
        cout << originalni_broj << " je djeljiv svakom svojom cifrom." << endl;
    } else {
        cout << originalni_broj << " nije djeljiv svakom svojom cifrom." << endl;
    }

    return 0;
}
