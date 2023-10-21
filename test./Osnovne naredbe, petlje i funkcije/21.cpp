#include <iostream>
using namespace std;

int obrnut = 0;

int okreni(int n) {
    if (n == 0) {
        return 0;
    } else {
        obrnut = obrnut * 10 + n % 10;
        okreni(n / 10);
    }
    return obrnut;
}

int main() {
    int n;
    cout << "Unesite prirodan broj: ";
    cin >> n;

    int obrnut = okreni(n);
    cout << "Obrnut broj: " << obrnut << endl;

    return 0;
}
