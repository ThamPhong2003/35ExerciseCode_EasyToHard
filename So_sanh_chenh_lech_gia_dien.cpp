#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int kwh;
    double currentPrices[6] = {1728, 1786, 2074, 2612, 2919, 3015};
    double newPrices[5] = {1728, 2074, 2612, 3111, 3457};
    double vatRate = 0.1;
    cin >> kwh;
    double currentTotalPrice = 0.0;
    double newTotalPrice = 0.0;
    if (kwh <= 50) {
        currentTotalPrice = kwh * currentPrices[0];
    } else if (kwh <= 100) {
        currentTotalPrice = 50 * currentPrices[0] + (kwh - 50) * currentPrices[1];
    } else if (kwh <= 200) {
        currentTotalPrice = 50 * currentPrices[0] + 50 * currentPrices[1] + (kwh - 100) * currentPrices[2];
    } else if (kwh <= 300) {
        currentTotalPrice = 50 * currentPrices[0] + 50 * currentPrices[1] + 100 * currentPrices[2] + (kwh - 200) * currentPrices[3];
    } else if (kwh <= 400) {
        currentTotalPrice = 50 * currentPrices[0] + 50 * currentPrices[1] + 100 * currentPrices[2] + 100 * currentPrices[3] + (kwh - 300) * currentPrices[4];
    } else {
        currentTotalPrice = 50 * currentPrices[0] + 50 * currentPrices[1] + 100 * currentPrices[2] + 100 * currentPrices[3] + 100 * currentPrices[4] + (kwh - 400) * currentPrices[5];
    }

    if (kwh <= 100) {
        newTotalPrice = kwh * newPrices[0];
    } else if (kwh <= 200) {
        newTotalPrice = 100 * newPrices[0] + (kwh - 100) * newPrices[1];
    } else if (kwh <= 400) {
        newTotalPrice = 100 * newPrices[0] + 100 * newPrices[1] + (kwh - 200) * newPrices[2];
    } else if (kwh <= 700) {
        newTotalPrice = 100 * newPrices[0] + 100 * newPrices[1] + 200 * newPrices[2] + (kwh - 400) * newPrices[3];
    } else {
        newTotalPrice = 100 * newPrices[0] + 100 * newPrices[1] + 200 * newPrices[2] + 300 * newPrices[3] + (kwh - 700) * newPrices[4];
    }

    currentTotalPrice *= (1 + vatRate);
    newTotalPrice *= (1 + vatRate);

    double difference = newTotalPrice - currentTotalPrice;

    cout << fixed << setprecision(2);
    cout << difference << endl;

    return 0;
}

