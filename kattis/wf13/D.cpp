#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, K;
vector<int> v;
bool check(int d) {
    int rem = N;
    int back = 2 * N * K;
    for (int a = 0; rem && a + 1 < back - 2 * (K - 1); a++) {
        if (v[a + 1] - v[a] <= d) {
            a++;
            rem--;
            back -= 2 * (K - 1);
        } else {
            back = min(back + 1, 2 * N * K);
        }
    }

    return rem == 0;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;
    for (int a = 0; a < 2 * N * K; a++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(allof(v));

    int lo = 0, hi = 1e9 + 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check (mid)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo;
}
