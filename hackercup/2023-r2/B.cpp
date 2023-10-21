#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 2e6 + 6;

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

const ll roll1 = 23;
const ll roll2 = 29;
// const ll roll1 = 10;
// const ll roll2 = 10;

ll pow1[MAXN];
ll pow2[MAXN];

ll qpow(ll x, ll y, ll mod) {
    ll ans = 1;
    while (y) {
        if (y & 1) {
            ans = ans * x % mod;
        }
        x = x * x % mod;
        y /= 2;
    }
    return ans;
}

const ll inv1 = qpow(roll1, MOD1 - 2, MOD1);
const ll inv2 = qpow(roll2, MOD2 - 2, MOD2);

struct myHash {
    ll x, y;
    void load(const deque<int> &dq) {
        x = 0;
        y = 0;
        int n = dq.size();
        for (int i = 0; i < n; i++) {
            x = (x + dq[i] * pow1[i]) % MOD1;
            y = (y + dq[i] * pow2[i]) % MOD2;
        }
    }
    bool operator==(const myHash& hsh) const {
        return x == hsh.x && y == hsh.y;
    }
    void push_front(ll tmp) {
        x = (x * roll1 + tmp) % MOD1;
        y = (y * roll2 + tmp) % MOD2;
    }
    void pop_front(ll tmp) {
        x = (x - tmp + MOD1) % MOD1;
        x = x * inv1 % MOD1;

        y = (y - tmp + MOD2) % MOD2;
        y = y * inv2 % MOD2;
    }

    void push_back(ll tmp, int n) {
        x = (x + pow1[n - 1] * tmp) % MOD1;
        y = (y + pow2[n - 1] * tmp) % MOD2;
    }
    void pop_back(ll tmp, int n) {
        x = (x - pow1[n - 1] * tmp) % MOD1;
        x = (x + MOD1) % MOD1;

        y = (y - pow2[n - 1] * tmp) % MOD2;
        y = (y + MOD2) % MOD2;
    }

    string to_str() const {
        return to_string(x) + ", " + to_string(y);
    }
};

int solve(int n, deque<int> A, deque<int> B) {
    reverse(B.begin(), B.end());

    myHash hashA;
    myHash hashB;
    hashA.load(A);
    hashB.load(B);

    for (int step = 0; step < 2 * n; step++) {
        // cout << "Compare " << hashA.to_str() << " vs " << hashB.to_str() << endl;
        if (hashA == hashB && A == B) {
            // cout << "Match compare" << endl;
            bool good = true;
            for (int i = 0; i < n / 2; i++) {
                good &= A[i] < B[n - i - 1];
                // cout << "Assert " << A[i] << " < " << B[i] << endl;
            } 
            for (int i = (n + 1) / 2; i < n; i++) {
                good &= A[i] > B[n - i - 1];
                // cout << "Assert " << A[i] << " > " << B[i] << endl;
            }
            if (good) {
                return step;
            } else {
                // cout << "Not good!\n";
            }
        }
        // shift
        int A1 = A.front();
        int B1 = B.back();
        A.pop_front();
        B.pop_back();
        A.push_back(B1);
        B.push_front(A1);

        hashA.pop_front(A1);
        hashA.push_back(B1, n);

        hashB.pop_back(B1, n);
        hashB.push_front(A1);
    }
    return -1;
}

int main() {
    pow1[0] = 1;
    pow2[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pow1[i] = pow1[i - 1] * roll1 % MOD1;
        pow2[i] = pow2[i - 1] * roll2 % MOD2;
    }

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        deque<int> A(n), B(n);
        for (int &Ai : A) {
            cin >> Ai;
            // Ai++;
        }
        for (int &Bi : B) {
            cin >> Bi;
            // Bi++;
        }
        cout << "Case #" << t << ": " << solve(n, A, B) << endl;
    }
}