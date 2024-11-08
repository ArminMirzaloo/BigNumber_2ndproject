#ifndef BIGNUMBER2_BIGPOWER_H
#define BIGNUMBER2_BIGPOWER_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class BigPower {
public:
    // Function to calculate base^exponent for large base
    string power(string base, int exponent) {
        if (exponent == 0) return "1";   // Any number to the power of 0 is 1
        if (exponent == 1) return base;   // Any number to the power of 1 is itself

        // Perform optimized power calculation
        string halfPower = power(base, exponent / 2);

        // Calculate the full power based on whether exponent is odd or even
        string result = multiplyBigNumbers(halfPower, halfPower);
        if (exponent % 2 != 0) {
            result = multiplyBigNumbers(result, base);
        }

        return result;
    }

private:
    // Function to multiply two large numbers represented as strings
    string multiplyBigNumbers(const string& num1, const string& num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        int maxLen = len1 + len2;
        int result[maxLen] = {0};  // Initialize an array to store the result

        // Multiply each digit of num1 with each digit of num2 and add to result
        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];

                result[i + j + 1] = sum % 10;        // Current digit
                result[i + j] += sum / 10;           // Carry over to the next position
            }
        }

        // Convert result array to string and remove leading zeros
        string resultStr = "";
        bool leadingZero = true;
        for (int i = 0; i < maxLen; i++) {
            if (result[i] == 0 && leadingZero) continue; // Skip leading zeros
            leadingZero = false;
            resultStr += (result[i] + '0');
        }

        return resultStr.empty() ? "0" : resultStr;
    }
};

#endif //BIGNUMBER2_BIGPOWER_H
