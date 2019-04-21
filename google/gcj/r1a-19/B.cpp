#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int sum[7];
int mod[7] = {16, 9, 5, 7, 11, 13, 17};

void testcase () {
    for (int a = 0; a < 7; a++) {
        sum[a] = 0;
        for (int b = 0; b < 18; b++) {
            cout << mod[a] << " ";
        }
        cout << endl;
        for (int b = 0; b < 18; b++) {
            int x;
            cin >> x;
            sum[a] += x;
        }
        sum[a] %= mod[a];
    }
    for (int a = 0; a < 1000005; a++) {
        bool good = true;
        for (int b = 0; b < 7; b++) {
            good &= sum[b] == a % mod[b];
        }
        if (good) {
            cout << a << endl;
            int verdict;
            cin >> verdict;
            return;
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T, N, M;
    cin >> T >> N >> M;
    for (int a = 1; a <= T; a++) {
        testcase();
    }
}
