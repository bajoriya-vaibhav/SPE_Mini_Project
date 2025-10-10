#include <iostream>
#include "../include/calculator.h"

using namespace std;

int main() {
    int choice;
    double x, y;

    while (true) {
        cout << "\n=== Scientific Calculator ===\n";
        cout << "1. Square Root\n";
        cout << "2. Factorial\n";
        cout << "3. Natural Logarithm (ln)\n";
        cout << "4. Power Function (x^b)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cout << "Enter number: ";
                    cin >> x;
                    cout << "√" << x << " = " << Calculator::squareRoot(x) << endl;
                    break;
                case 2:
                    cout << "Enter integer: ";
                    cin >> x;
                    cout << x << "! = " << Calculator::factorial((int)x) << endl;
                    break;
                case 3:
                    cout << "Enter number: ";
                    cin >> x;
                    cout << "ln(" << x << ") = " << Calculator::naturalLog(x) << endl;
                    break;
                case 4:
                    cout << "Enter base: ";
                    cin >> x;
                    cout << "Enter exponent: ";
                    cin >> y;
                    cout << x << "^" << y << " = " << Calculator::power(x, y) << endl;
                    break;
                case 5:
                    cout << "Exiting..." << endl;
                    return 0;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        } catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}