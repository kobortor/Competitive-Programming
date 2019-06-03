#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int query(vector<int> va, vector<int> vb) {
    cout << va.size() << " " << vb.size() << " ";
    for (int i : va) cout << i << " ";
    for (int i : vb) cout << i << " ";
    cout << endl;
    int ans;
    cin >> ans;
    return ans;
}

vector<int> mylist(int l, int r) {
    vector<int> v;
    for(int a = l; a <= r; a++) {
        v.push_back(a);
    }
    return v;
}

void testcase() {
    int N;
    cin >> N;

    vector<int> v1 = {1};
    vector<int> v2 = mylist(2, N);
    int best = query(v1, v2);

    for (int a = 0; a < 7; a++) {
        vector<int> v3, vnot;
        for (int i : v2) {
            if (i & (1 << a)) {
                v3.push_back(i);
            } else {
                vnot.push_back(i);
            }
        }

        if (v3.empty()) {
            v3.swap(vnot);
        }

        int tmp = query(v1, v3);
        if (tmp == best) {
            v2 = v3;
        } else {
            v2 = vnot;
        }
    }

    //now v2 is size 1
    v1.clear();
    for (int a = 1; a <= N; a++) {
        if (a != v2[0]){
            v1.push_back(a);
        }
    }

    int ans = query(v1, v2);

    cout << "-1 " << ans << endl;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        testcase();
    }
}
