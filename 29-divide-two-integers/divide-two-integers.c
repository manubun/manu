

int divide(int dividend, int divisor) {
    // Handle overflow cases
    if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
        return INT_MAX;
    }

    // Determine sign of the result
    int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

    // Convert both dividend and divisor to positive numbers
    long long ldividend = labs(dividend);
    long long ldivisor = labs(divisor);

    // Initialize quotient
    long long quotient = 0;

    // Perform division
    while (ldividend >= ldivisor) {
        long long temp = ldivisor, multiple = 1;
        while (ldividend >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        ldividend -= temp;
        quotient += multiple;
    }

    // Adjust the sign of the quotient
    if (sign < 0) {
        quotient = -quotient;
    }

    // Handle overflow cases
    if (quotient > INT_MAX || quotient < INT_MIN) {
        return INT_MAX;
    }

    return (int)quotient;
}
