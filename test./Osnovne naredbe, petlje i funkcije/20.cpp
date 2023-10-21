#include <iostream>
using namespace std;

void stampaj_trougao(float x1, float y1, float x2, float y2, float x3, float y3) {

    float najblize_x, najblize_y;
    float udaljenost = x1 * x1 + y1 * y1;

    if (x2 * x2 + y2 * y2 < udaljenost) {
        najblize_x = x2;
        najblize_y = y2;
        udaljenost = x2 * x2 + y2 * y2;
    }

    if (x3 * x3 + y3 * y3 < udaljenost) {
        najblize_x = x3;
        najblize_y = y3;
    }

    cout << "Tjemena trougla u smjeru kazaljke na satu počevši od najbližeg koordinatnom početku:" << endl;
    cout << "(" << najblize_x << ", " << najblize_y << ") ";

    // Odabiremo drugo tjeme
    if (najblize_x == x1 && najblize_y == y1) {
        if (x2 * (y3 - y1) - y2 * (x3 - x1) > 0) {
            cout << "(" << x2 << ", " << y2 << ") ";
            cout << "(" << x3 << ", " << y3 << ") ";
        } else {
            cout << "(" << x3 << ", " << y3 << ") ";
            cout << "(" << x2 << ", " << y2 << ") ";
        }
    } else if (najblize_x == x2 && najblize_y == y2) {
        if (x3 * (y1 - y2) - y3 * (x1 - x2) > 0) {
            cout << "(" << x3 << ", " << y3 << ") ";
            cout << "(" << x1 << ", " << y1 << ") ";
        } else {
            cout << "(" << x1 << ", " << y1 << ") ";
            cout << "(" << x3 << ", " << y3 << ") ";
        }
    } else {
        if (x1 * (y2 - y3) - y1 * (x2 - x3) > 0) {
            cout << "(" << x1 << ", " << y1 << ") ";
            cout << "(" << x2 << ", " << y2 << ") ";
        } else {
            cout << "(" << x2 << ", " << y2 << ") ";
            cout << "(" << x1 << ", " << y1 << ") ";
        }
    }
}

int main() {
    float x1, y1, x2, y2, x3, y3;

    cout << "Unesite koordinate tjemena trougla (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Unesite koordinate tjemena trougla (x2, y2): ";
    cin >> x2 >> y2;
    cout << "Unesite koordinate tjemena trougla (x3, y3): ";
    cin >> x3 >> y3;

    stampaj_trougao(x1, y1, x2, y2, x3, y3);

    return 0;
}
