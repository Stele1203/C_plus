#include <iostream>
#include <cmath>
using namespace std;

float povrsina(float x1, float y1, float x2, float y2, float x3, float y3) {

    float povrsina = 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    return povrsina;
}

int main() {
    float x1, y1, x2, y2, x3, y3;

    cout << "Unesite koordinate tjemena trougla (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Unesite koordinate tjemena trougla (x2, y2): ";
    cin >> x2 >> y2;
    cout << "Unesite koordinate tjemena trougla (x3, y3): ";
    cin >> x3 >> y3;

    float p = povrsina(x1, y1, x2, y2, x3, y3);

    cout << "Površina trougla je: " << p << endl;

    return 0;
}
