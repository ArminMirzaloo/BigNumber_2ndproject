#ifndef BIGNUMBER2_MULTIPLY_H
#define BIGNUMBER2_MULTIPLY_H

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Multiply {
public:
    // Constructor that takes two large numbers as strings
    Multiply(string num1, string num2) {
        // Check for negative numbers and set flags
        if (num1[0] == '-') {
            isNegative1 = true;
            num1 = num1.substr(1);              // Remove the negative sign
        }
        if (num2[0] == '-') {
            isNegative2 = true;
            num2 = num2.substr(1);              // Remove the negative sign
        }

        number1 = num1;
        number2 = num2;
    }

    // Function to multiply the two numbers
    string multiply() {
        int len1 = number1.size();
        int len2 = number2.size();

        if (len1 == 0 || len2 == 0) return "0";

        // Result can be maximum of len1 + len2 digits
        int* result = new int[len1 + len2];
        memset(result, 0, (len1 + len2) * sizeof(int));

        // Indices for positioning in the result
        int pos1 = 0, pos2 = 0;

        // Loop through each digit of the first number
        for (int i = len1 - 1; i >= 0; i--) {
            int carry = 0;
            int n1 = number1[i] - '0';
            pos2 = 0;

            // Loop through each digit of the second number
            for (int j = len2 - 1; j >= 0; j--) {
                int n2 = number2[j] - '0';
                int sum = n1 * n2 + result[pos1 + pos2] + carry;
                carry = sum / 10;
                result[pos1 + pos2] = sum % 10;
                pos2++;
            }

            if (carry > 0) result[pos1 + pos2] += carry;
            pos1++;
        }

        // Skip leading zeros
        int i = len1 + len2 - 1;
        while (i >= 0 && result[i] == 0) i--;

        if (i == -1) {
            delete[] result;
            return "0";
        }

        // Convert result to a string
        string resultStr;
        if ((isNegative1 ^ isNegative2) && i >= 0)              // Add negative sign if one number is negative
            resultStr += "-";

        while (i >= 0) resultStr += to_string(result[i--]);

        delete[] result;
        return resultStr;
    }

private:
    string number1;
    string number2;
    bool isNegative1 = false;
    bool isNegative2 = false;
};



#endif //BIGNUMBER2_MULTIPLY_H
