#include <iostream>
#include <string>
using namespace std;

int main() {
    string date;
    cin >> date;

    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        cout << "INCORRECT" << endl;
        return 0;
    }

    int year, month, day;
    if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
        cout << "INCORRECT" << endl;
        return 0;
    }


    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31) {
        cout << "INCORRECT" << endl;
        return 0;
    }

    cout << year << " " << month << " " << day << endl;

    return 0;
}

