#include <iostream>
#include <cmath>
using namespace std;

struct Tacka {
    double x;
    double y;
};

bool kolinearan(Tacka p1, Tacka p2, Tacka p3) {
    double povrsina = 0.5 * (p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y));
    return fabs(povrsina) < 0.001;
}

int main() {
    int n;
    cin >> n;

    Tacka *tacke = new Tacka[n];

    for (int i = 0; i < n; i++) {
        cin >> tacke[i].x >> tacke[i].y;
    }

    for (int i = 0; i < n - 2; i++) {
        if (!kolinearan(tacke[i], tacke[i + 1], tacke[i + 2])) {
            cout << "NE" << endl;
            delete[] tacke;
            return 0;
        }
    }

    cout << "DA" << endl;
    delete[] tacke;
    return 0;
}
