int helper(long long n) {
    int ans = 0;
    long long ones = 1;
    while (true) {
        for (long long i = 1; i <= 9; i++) {
            if (ones * i <= n) {
                ans++;
            } else {
                return ans;
            }
        }
        ones = 10 * ones + 1;
    }
}

int getUniformIntegerCountInInterval(long long A, long long B) {
    return helper(B) - helper(A - 1);
}
