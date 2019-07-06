#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 7;

struct bloomfilter {
    bitset<MAXN> bits;

    vector<int> get_hashes(string s) {
        vector<int> vec;
        for (int i = 3; i < 50; i += 2) {
            int mod = MAXN;
            int ans = 0;
            for (char c : s) {
                ans = (ans * i + c - 'a' + 1) % mod;
            }

            vec.push_back(ans);
        }

        return vec;
    }

    void insert (string s) {
        for (int i : get_hashes(s)) {
            bits[i] = true;
        }
    }

    bool seen(string s) {
        for (int i : get_hashes(s)) {
            if (!bits[i]) return false;
        }

        return true;
    }
} bf;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    for (int a = 0; a < n; a++) {
        string s;
        cin >> s;

        cout << (bf.seen(s) ? "YES\n" : "NO\n");

        bf.insert(s);
    }
}
