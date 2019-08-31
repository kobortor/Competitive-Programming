#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, x;
    cin >> n >> x;

    vector<vector<int>> friendlist(n);
    for (vector<int> &v : friendlist) {
        int k;
        cin >> k;
        while (k--) {
            int di;
            cin >> di;
            v.push_back(di - 1);
        }
    }

    set<int> st;
    for (int i : friendlist[x - 1]) {
        st.insert(allof(friendlist[i]));
    }
    for (int i : friendlist[x - 1]) {
        st.erase(i);
    }
    st.erase(x - 1);

    cout << st.size() << endl;
    for (int i : st) cout << i + 1 << endl;
}
