int getMinProblemCount(int N, vector<int> S) {
    bool odd = false;
    int answer = 0;
    for (int x : S) {
        odd |= (x % 2);
        answer = max(answer, x / 2);
    }

    return answer + odd;
}
