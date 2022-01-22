int getMaximumEatenDishCount(int N, vector<int> D, int K) {
    queue<int> q;
    set<int> st;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (st.count(D[i]) == 0) {
            ans++;
            st.insert(D[i]);
            q.push(D[i]);

            if (q.size() > K) {
                st.erase(q.front());
                q.pop();
            }
        }
    }
    return ans;
}
