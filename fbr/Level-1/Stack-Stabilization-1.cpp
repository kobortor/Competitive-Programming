int getMiniumDeflatedDiscCount(int N, vector<int> R) {
    reverse(R.begin(), R.end());
    int best = 2e9;
    int ans = 0;
    for (int x : R) {
        if (x >= best) {
            if (best == 1) {
                return -1;
            } else {
                ans++;
                x = best - 1;
            }
        }
        best = x;
    }
    return ans;
}
