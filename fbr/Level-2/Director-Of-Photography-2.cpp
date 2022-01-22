long long helper(int N, string C, int X, int Y) {
    queue<int> q_photographer, q_backdrop;
    for (int i = 0; i < Y; i++) {
        if (C[i] == 'B') {
            q_backdrop.push(i);
        }
    }

    long long ans = 0;

    for (int i = 0; i < N; i++) {
        if (i + Y < N && C[i + Y] == 'B') {
            q_backdrop.push(i + Y);
        }
        if (i - X >= 0 && C[i - X] == 'P') {
            q_photographer.push(i - X);
        }

        while (!q_backdrop.empty() && q_backdrop.front() < i + X) q_backdrop.pop();
        while (!q_photographer.empty() && q_photographer.front() < i - Y) q_photographer.pop();

        if (C[i] == 'A') {
            ans += (long long) q_backdrop.size() * (long long) q_photographer.size();
        }
    }
    return ans;
}

long long getArtisticPhotographCount(int N, string C, int X, int Y) {
    long long tmp = helper(N, C, X, Y);
    reverse(C.begin(), C.end());
    return tmp + helper(N, C, X, Y);
}
