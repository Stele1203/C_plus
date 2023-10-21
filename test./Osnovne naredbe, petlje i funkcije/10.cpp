#include <iostream>
#include <cmath>
using namespace std;

bool prostBroj(int n) {
    if (n <= 1) {
        return false;
    }

    if (n == 2) {
        return true;
    }

    if (n % 2 == 0) {
        return false;
    }

    int sqrtN = sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void stampaProsteFaktore(int n) {
    cout << "Faktori broja " << n << " su: ";
    for (int i = 2; i <= n; i++) {
        if (n % i == 0 && prostBroj(i)) {
            cout << i << " ";
        }
    }
}

int main() {
    stampaProsteFaktore(60);

    return 0;
}
