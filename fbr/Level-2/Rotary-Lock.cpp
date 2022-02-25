#include <bits/stdc++.h>

using namespace std;

long long diff(long long x, long long y, long long N) {
    long long diff = abs(x - y);
    return min(diff, N - diff);
}

long long getMinCodeEntryTime(int N, int M, vector<int> C) {
    C.insert(C.begin(), 1);
    vector<long long> dp(M + 2, (long long)1e15);

    dp[0] = diff(C[0], C[1], N);

    for (int i = 2; i <= M; i++) {
        int to_add = diff(C[i-1], C[i], N);
        for (int j = 0; j + 1 < i; j++) {
            dp[i-1] = min(dp[i-1], dp[j] + diff(C[i], C[j], N));
            dp[j] += to_add;
        }
    }

    return *min_element(dp.begin(), dp.end());
}