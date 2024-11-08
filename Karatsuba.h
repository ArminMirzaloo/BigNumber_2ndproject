#ifndef BIGNUMBER2_KARATSUBA_H
#define BIGNUMBER2_KARATSUBA_H

#include <iostream>
#include <string>

using namespace std;

class Karatsuba {
public:
    // Constructor that takes two large numbers as strings
    Karatsuba(const string& num1, const string& num2) : number1(num1), number2(num2) {}

    // Main function to perform Karatsuba multiplication
    string multiply() {
        bool isNegativeResult = false;

        // Check if either number is negative
        string num1 = number1;
        string num2 = number2;

        if (num1[0] == '-') {
            isNegativeResult = !isNegativeResult; // Flip the sign
            num1 = num1.substr(1); // Remove the negative sign
        }

        if (num2[0] == '-') {
            isNegativeResult = !isNegativeResult; // Flip the sign
            num2 = num2.substr(1); // Remove the negative sign
        }

        // Perform Karatsuba multiplication on absolute values
        string result = karatsuba(num1, num2);

        // Apply negative sign if needed
        if (isNegativeResult && result != "0") {
            result = "-" + result;
        }

        return result;
    }

private:
    string number1;
    string number2;

    // Helper function to add two strings as large numbers
    string addStrings(const string& num1, const string& num2) {
        string result = "";
        int carry = 0;
        int i = num1.size() - 1, j = num2.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            result = to_string(sum % 10) + result;
            carry = sum / 10;
        }

        return result;
    }

    // Helper function to subtract two strings as large numbers
    string subtractStrings(const string& num1, const string& num2) {
        string result = "";
        int borrow = 0;
        int i = num1.size() - 1, j = num2.size() - 1;

        while (i >= 0 || j >= 0) {
            int diff = (num1[i--] - '0') - (j >= 0 ? num2[j--] - '0' : 0) - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result = to_string(diff) + result;
        }

        // Remove leading zeros
        while (result.size() > 1 && result[0] == '0') result.erase(0, 1);

        return result;
    }

    // Helper function to pad zeros to the right of a number (equivalent to multiplying by 10^m)
    string padZeros(const string& num, int m) {
        return num + string(m, '0');
    }

    // Recursive function implementing Karatsuba multiplication
    string karatsuba(string x, string y) {
        int n = max(x.size(), y.size());

        // Base case: if the length of the number is 1, multiply directly
        if (n == 1) {
            int product = (x[0] - '0') * (y[0] - '0');
            return to_string(product);
        }

        // Pad the numbers with leading zeros to make them the same length
        while (x.size() < n) x = "0" + x;
        while (y.size() < n) y = "0" + y;

        int m = n / 2;

        // Split the numbers into two halves
        string a = x.substr(0, x.size() - m);
        string b = x.substr(x.size() - m);
        string c = y.substr(0, y.size() - m);
        string d = y.substr(y.size() - m);

        // Recursive calls for the three multiplications
        string z2 = karatsuba(a, c);
        string z0 = karatsuba(b, d);
        string z1 = karatsuba(addStrings(a, b), addStrings(c, d));

        // Calculate (z1 - z2 - z0) and combine results
        string middle = subtractStrings(subtractStrings(z1, z2), z0);

        // Final result by combining all parts with appropriate power of tens
        return addStrings(addStrings(padZeros(z2, 2 * m), padZeros(middle, m)), z0);
    }
};

#endif //BIGNUMBER2_KARATSUBA_H
