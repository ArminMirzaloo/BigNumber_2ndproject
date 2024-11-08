#ifndef BIGNUMBER2_BIGFACTORIAL_H
#define BIGNUMBER2_BIGFACTORIAL_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class BigFactorial {
public:
    // Function to calculate factorial of a number and return it as a string
    string calculateFactorial(int n) {
        // Initialize the result as a string containing "1"
        string result = "1";

        // Multiply the result by each number from 2 to n
        for (int i = 2; i <= n; i++) {
            result = multiplyBigNumbers(result, to_string(i));
        }

        return result;
    }

private:
    // Function to multiply two large numbers represented as strings
    string multiplyBigNumbers(const string& num1, const string& num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        vector<int> result(len1 + len2, 0); // To store the result of multiplication

        // Multiply each digit of num1 with each digit of num2 and add to result
        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];

                result[i + j + 1] = sum % 10;  // Current digit
                result[i + j] += sum / 10;     // Carry over
            }
        }

        // Convert result vector to string and remove leading zeros
        string resultStr = "";
        for (int i = 0; i < result.size(); i++) {
            if (!(resultStr.empty() && result[i] == 0)) {
                resultStr += to_string(result[i]);
            }
        }

        return resultStr.empty() ? "0" : resultStr;
    }
};

#endif //BIGNUMBER2_BIGFACTORIAL_H
