#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll DIM = 90;
const ll mod = 1e9 + 7;

struct Vector {
    ll data[DIM];
    Vector() {
        fill(data, data + DIM, 0ll);
    }
};

struct Matrix {
    ll data[DIM][DIM];
    Matrix() {
        for (int i = 0; i < DIM; i++) {
            for (int j = 0; j < DIM; j++) {
                data[i][j] = 0;
            }
        }
    }
    Matrix operator*(Matrix m) {
        Matrix out;
        for (int i = 0; i < DIM; i++) {
            for (int j = 0; j < DIM; j++) {
                for (int k = 0; k < DIM; k++) {
                    out.data[i][j] += this->data[i][k] * m.data[k][j];
                    out.data[i][j] %= mod;
                }
            }
        }
        return out;
    }

    Vector operator*(Vector v) {
        Vector out;
        for (int i = 0; i < DIM; i++) {
            for (int j = 0; j < DIM; j++) {
                out.data[j] += this->data[i][j] * v.data[i];
                out.data[j] %= mod;
            }
        } 
        return out;
    }
};

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll A, B;
    cin >> A >> B;

    ll ans = 0;
    if (A == 1) {
        for (int i = 1; i <= 9; i++) {
            if (i % 225 == B) {
                ans++;
            }
        }
    } else if (A == 2) {
        for (int i = 10; i <= 99; i++) {
            int dig1 = i % 10;
            int dig2 = i / 10;
            if (dig1 != dig2 && i % 225 == B) {
                ans++;
            }
        }
    } else {
        Vector v0{};
        for (int i = 1; i <= 99; i++) {
            int dig1 = i % 10;
            int dig2 = i / 10;
            if ((i - B) % 25 != 0) {
                continue;
            }
            if (dig1 == dig2) {
                continue;
            }

            int targ_p = (i - B) / 25;
            if (targ_p < 0) {
                targ_p += 9;
            }

            int state = dig2 * 9 + targ_p;

            v0.data[state]++;
        }

        Matrix M{};
        for (int i = 0; i < 10; i++) {
            for (int p = 0; p < 9; p++) {
                int state1 = i * 9 + p;
                for (int j = 0; j < 10; j++) {
                    if (i == j) continue;

                    int q = (p + 4 * j) % 9;
                    int state2 = j * 9 + q;

                    M.data[state1][state2] = 1;
                }
            }
        }

        ll power = A - 2;
        Matrix mpow{};
        for (int i = 0; i < DIM; i++) {
            mpow.data[i][i] = 1;
        }
        while (power) {
            if (power & 1) {
                mpow = mpow * M;
            }
            M = M * M;
            power >>= 1;
        }

        Vector out = mpow * v0;
        for (int i = 1; i <= 9; i++) {
            int p = 0;
            int state = i * 9 + p;
            ans += out.data[state];
        }
        ans %= mod;
    }


    // ll slow_ans = 0;
    // int lim = 0;
    // for (int i = pow(10, A - 1); i < pow(10, A); i++) {
    //     string s = to_string(i);
    //     if (i % 225 == B) {
    //         bool dup = false;
    //         for (int j = 0; j + 1 < (int)s.size(); j++) {
    //             if (s[j] == s[j + 1]) {
    //                 dup = true;
    //                 continue;
    //             }
    //         }
    //         if (!dup) {
    //             slow_ans++;
    //             cout << "Slow: " << i << "\n";
    //         }
    //     }
    // }
    // cout << "SLow ans = " << slow_ans << endl;
    cout << ans << "\n";
}
