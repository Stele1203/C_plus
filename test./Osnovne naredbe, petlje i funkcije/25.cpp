#include <iostream>

bool provjeriSkupProstihFaktora(int broj) {
    while (broj % 2 == 0) {
        broj /= 2;
    }
    while (broj % 3 == 0) {
        broj /= 3;
    }
    while (broj % 5 == 0) {
        broj /= 5;
    }

    return broj == 1;
}

int main() {
    int broj;
    std::cout << "Unesite prirodan broj: ";
    std::cin >> broj;

    bool rezultat = provjeriSkupProstihFaktora(broj);

    if (rezultat) {
        std::cout << "Skup prostih faktora broja " << broj << " je ograničen na 2, 3 i 5." << std::endl;
    } else {
        std::cout << "Skup prostih faktora broja " << broj << " nije ograničen na 2, 3 i 5." << std::endl;
    }

    return 0;
}
