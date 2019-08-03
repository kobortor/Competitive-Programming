#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 4e5 + 5;

struct bit {
    int data[MAXN];
    void update (int pos) {
        while (pos < MAXN) {
            data[pos]++;
            pos += pos & -pos;
        }
    }
    int query (int pos) {
        int ans = 0;
        while (pos) {
            ans += data[pos];
            pos -= pos & -pos;
        }
        return ans;
    }
} ds;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<int> uniq;
    vector<int> A, B;
    while (n--) {
        int a;
        cin >> a;
        A.push_back(a);
        uniq.push_back(a);
    }

    while (m--) {
        int b;
        cin >> b;
        B.push_back(b);
        uniq.push_back(b);
    }

    sort(allof(uniq));
    for (int i : A) ds.update(lower_bound(allof(uniq), i) - uniq.begin() + 1);
    for (int i : B) cout << ds.query(lower_bound(allof(uniq), i) - uniq.begin() + 1) << " ";
}
