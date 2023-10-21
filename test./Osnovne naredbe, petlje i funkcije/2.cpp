#include <iostream>
using namespace std;

int main() {
    double fileSizeInGB;
    const double networkSpeedMbps = 100.0;
    const double bitsInByte = 8.0;


    cin >> fileSizeInGB;


    double fileSizeInMB = fileSizeInGB * 1024;
    double fileSizeInBits = fileSizeInMB * bitsInByte;
    double transferTimeSeconds = fileSizeInBits / networkSpeedMbps;

    cout << "Vrijeme za prijenos fajla: " << transferTimeSeconds << " sekundi" << endl;

    return 0;
}
