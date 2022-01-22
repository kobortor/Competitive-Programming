long long getSecondsRequired(long long N, int F, vector<long long> P) {
    return N - *min_element(P.begin(), P.end());
}
