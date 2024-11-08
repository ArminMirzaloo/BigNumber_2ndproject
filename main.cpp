#include "Multiply.h"
#include "Karatsuba.h"
#include "Divide.h"
#include "BigFactorial.h"
#include "BigPower.h"

int main() {
    int i;

    while(true) {
        cin >> i;

        if (i == 1) {
            string num1, num2;

            cout << "Enter the first large number: ";
            cin >> num1;

            cout << "Enter the second large number: ";
            cin >> num2;

            Multiply bigMultiply(num1, num2);
            cout << "Result: " << bigMultiply.multiply() << endl;
        }

        else if (i == 2) {
            string num1, num2;

            cout << "Enter the first large number: ";
            cin >> num1;

            cout << "Enter the second large number: ";
            cin >> num2;
            // Create an instance of Karatsuba and multiply the numbers
            Karatsuba karatsuba(num1, num2);
            cout << "Result: " << karatsuba.multiply() << endl;
        }

        else if (i == 3) {
            Divide divider;
            string num1, num2;

            // Take input from user
            cout << "Enter the first large number: ";
            cin >> num1;

            cout << "Enter the second large number: ";
            cin >> num2;

            // Perform division and print the result
            string result = divider.divide(num1, num2);

            // Only print result if the division was valid (i.e., not a division by zero)
            if (!result.empty()) {
                cout << "Result: " << result << endl;
            }
        }

        else if (i == 4) {
            BigFactorial factorialCalculator;
            int num;

            // Take input from the user
            cout << "Enter a number between 1 and 100: ";
            cin >> num;

            // Calculate and print the factorial of the number
            string result = factorialCalculator.calculateFactorial(num);
            cout << "Factorial of " << num << " is: " << result << endl;
        }

        else if (i == 5) {
            BigPower powerCalculator;
            string base;
            int exponent;

            // Take input from the user
            cout << "Enter a large base number: ";
            cin >> base;

            cout << "Enter an exponent: ";
            cin >> exponent;

            // Calculate and print the result of base^exponent
            string result = powerCalculator.power(base, exponent);
            cout << "Result: " << result << endl;
        }

        else if (i == 0)
            exit(0);
    }
}
