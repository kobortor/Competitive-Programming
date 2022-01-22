int getArtisticPhotographCount(int N, string C, int X, int Y) {
    // Very naive solution
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                int d1 = abs(i - j);
                int d2 = abs(j - k);

                if ((i - j) * (j - k) > 0 && 
                    C[i] == 'P' && C[j] == 'A' && C[k] == 'B' && 
                    X <= d1 && d1 <= Y && 
                    X <= d2 && d2 <= Y) {
                    ans++;
                }
            }
        }
    }
    return ans;
}
