long long getMinCodeEntryTime(int N, int M, vector<int> C) {
    int last = 1;
    long long ans = 0;
    for (int x : C) {
        int diff = abs(x - last);
        ans += min(diff, N - diff);
        last = x;
    }
    return ans;
}
