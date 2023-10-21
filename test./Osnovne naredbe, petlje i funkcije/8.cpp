#include <iostream>
using namespace std;

int main() {
    cout << "Dvocifreni Pitagorini brojevi su:" << endl;
    for (int c = 10; c <= 99; c++) { // Petlja za dvocifrene brojeve c
        for (int a = 1; a <= c; a++) {
            for (int b = a; b <= c; b++) {
                if (c * c == a * a + b * b) {
                    cout << "c = " << c << ", a = " << a << ", b = " << b << endl;
                }
            }
        }
    }

    return 0;
}
