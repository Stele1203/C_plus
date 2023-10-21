#include <iostream>
using namespace std;

float broj_riba(int x, int p, int s) {
    int godine = 0;
    while (s > x) {
        s -= (p / 100.0) * s;
        godine++;
    }
    return godine;
}

int main() {
    int x, p, s;
    cout << "Unesite kritičnu vrijednost x: ";
    cin >> x;
    cout << "Unesite procenat smanjenja p: ";
    cin >> p;
    cout << "Unesite trenutni broj riba s: ";
    cin >> s;

    float godine = broj_riba(x, p, s);
    cout << "Broj godina potreban da broj riba padne ispod " << x << ": " << godine << endl;

    return 0;
}
