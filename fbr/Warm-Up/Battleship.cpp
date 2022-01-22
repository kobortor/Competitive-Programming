double getHitProbability(int R, int C, vector<vector<int>> G) {
    int answer = 0;
    for (const vector<int> &v : G) 
        answer += accumulate(v.begin(), v.end(), 0);

    return (double) answer / (R*C);
}
