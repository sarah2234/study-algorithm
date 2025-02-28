bool isPalindrome(int x) {
    if (x < 0) return false;

    int length = (int)log10(x) + 1;

    while (x > 0)
    {
        if (x % 10 != x / (int)pow(10, length - 1)) return false;

        x %= (int)pow(10, length - 1);
        x /= 10;
        length -= 2;
    }

    return true;
}