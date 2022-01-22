double getMaxExpectedProfit(int N, vector<int> V, int C, double S) {
    vector<double> dp(N + 1, -1e12);

    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        double val = 0;
        double decay = 1;
        double best = -1e12;
        for (int j = i; j >= 1; j--) {
            val += V[j - 1] * decay;
            best = max(best, val - C + dp[j - 1]);
            decay *= 1 - S;
        }
        dp[i] = best;
    }

    return *max_element(dp.begin(), dp.end());
}
