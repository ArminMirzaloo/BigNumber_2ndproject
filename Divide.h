#ifndef BIGNUMBER2_DIVIDE_H
#define BIGNUMBER2_DIVIDE_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Divide {
private:
    // Function to perform division on two large numbers represented as strings
    string divideBigNumbers(const string& dividend, const string& divisor) {
        string result = "";
        int len1 = dividend.length();
        int len2 = divisor.length();

        // If dividend is smaller than divisor, the result is zero
        if (len1 < len2) {
            return "0";
        }

        // Start with the first few digits of dividend
        string remainder = dividend.substr(0, len2 - 1);
        for (int i = len2 - 1; i < len1; i++) {
            remainder += dividend[i];
            int quotientDigit = 0;

            // Perform subtraction and count how many times divisor can fit into the remainder
            while (compareStrings(remainder, divisor) >= 0) {
                remainder = subtractStrings(remainder, divisor);
                quotientDigit++;
            }

            // Append the quotient digit
            result += (quotientDigit + '0');
        }

        // Remove leading zeros from the result
        result.erase(0, result.find_first_not_of('0'));
        return result.empty() ? "0" : result;
    }

    // Compare two large numbers as strings
    int compareStrings(const string& num1, const string& num2) {
        if (num1.length() > num2.length()) return 1;
        if (num1.length() < num2.length()) return -1;
        return num1.compare(num2);
    }

    // Subtract two large numbers represented as strings
    string subtractStrings(const string& num1, const string& num2) {
        string result = "";
        int len1 = num1.length(), len2 = num2.length();
        int carry = 0;

        // Perform subtraction digit by digit from right to left
        for (int i = 0; i < len1; i++) {
            int digit1 = num1[len1 - 1 - i] - '0';
            int digit2 = (i < len2) ? num2[len2 - 1 - i] - '0' : 0;

            int diff = digit1 - digit2 - carry;
            if (diff < 0) {
                diff += 10;
                carry = 1;
            } else {
                carry = 0;
            }
            result += (diff + '0');
        }

        // Remove leading zeros
        reverse(result.begin(), result.end());
        result.erase(0, result.find_first_not_of('0'));
        return result.empty() ? "0" : result;
    }

public:
    // Main function to divide two large numbers
    string divide(const string& num1, const string& num2) {
        // Check for division by zero
        if (num2 == "0") {
            cout << "Error: Division by zero is not allowed." << endl;
            return "";
        }

        // Check the signs of the numbers
        bool isNegative = (num1[0] == '-') ^ (num2[0] == '-'); // Result is negative if one number is negative

        // Remove the negative sign from the numbers if present
        string absNum1 = (num1[0] == '-') ? num1.substr(1) : num1;
        string absNum2 = (num2[0] == '-') ? num2.substr(1) : num2;

        // Perform the division
        string quotient = divideBigNumbers(absNum1, absNum2);

        // Add the negative sign if necessary
        if (isNegative && quotient != "0") {
            quotient = "-" + quotient;
        }

        return quotient;
    }
};


#endif //BIGNUMBER2_DIVIDE_H
