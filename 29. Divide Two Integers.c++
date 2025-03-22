#include <climits> // For INT_MAX and INT_MIN
#include <cmath>   // For abs function

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle edge cases
        if (divisor == 0) {
            throw std::invalid_argument("Divisor cannot be zero.");
        }
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; // Overflow case
        }

        // Determine the sign of the result
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert both numbers to positive
        long long absDividend = std::abs(static_cast<long long>(dividend));
        long long absDivisor = std::abs(static_cast<long long>(divisor));

        long long quotient = 0;

        // Perform bitwise division
        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor, multiple = 1;
            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }
            absDividend -= tempDivisor;
            quotient += multiple;
        }

        // Apply the sign to the quotient
        quotient = isNegative ? -quotient : quotient;

        // Ensure the quotient is within the 32-bit integer range
        if (quotient > INT_MAX) {
            return INT_MAX;
        }
        if (quotient < INT_MIN) {
            return INT_MIN;
        }

        return static_cast<int>(quotient);
    }
};
