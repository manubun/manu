bool isPalindrome(int x) {
    // Special cases:
    // If x is negative or x ends with 0 (except for 0 itself), it cannot be a palindrome.
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reversed = 0;
    while (x > reversed) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    // When the length of the number is an odd number, we can end up with reversed / 10
    // to eliminate the middle digit.
    return x == reversed || x == reversed / 10;
}
