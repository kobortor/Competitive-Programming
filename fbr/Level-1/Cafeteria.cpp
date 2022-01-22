long long getMaxAdditionalDinersCount(long long N, long long K, int M, vector<long long> S) {
    sort(S.begin(), S.end());

    long long answer = 0;

    // front
    answer += (S[0] - 1) / (K + 1);

    // back
    answer += (N - S.back()) / (K + 1);

    for (int i = 1; i < (int)S.size(); i++) {
        answer += (S[i] - S[i - 1]) / (K + 1) - 1;
    }

    return answer;
}
