long long maxDigitInNumber(long long n) {
    if(n < 10) return n;
    return max( maxDigitInNumber(n / 10), n % 10);
}