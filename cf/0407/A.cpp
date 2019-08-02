#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int a, b;
    cin >> a >> b;

    vector<pii> A, B;
    for (int i = 1; i < a; i++) {
        for (int j = 1; j < a; j++) {
            if (i * i + j * j == a * a) {
                A.push_back(pii(i, j));
                A.push_back(pii(i, -j));
                A.push_back(pii(-i, j));
                A.push_back(pii(-i, -j));
            }
        }
    }

    for (int i = 1; i < b; i++) {
        for (int j = 1; j < b; j++) {
            if (i * i + j * j == b * b) {
                B.push_back(pii(i, j));
                B.push_back(pii(i, -j));
                B.push_back(pii(-i, j));
                B.push_back(pii(-i, -j));
            }
        }
    }

    for (pii pa : A) {
        for (pii pb : B) {
            if (pa.first * pb.first + pa.second * pb.second == 0 &&
                pa.first != pb.first && pa.second != pb.second) {
                cout << "YES\n";
                cout << "0 0\n";
                cout << pa.first << " " << pa.second << "\n";
                cout << pb.first << " " << pb.second << "\n";
                return 0;
            }
        }
    }

    cout << "NO";
}
