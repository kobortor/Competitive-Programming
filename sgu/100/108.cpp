#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e7 + 7;

bool selfnum[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(selfnum, true, sizeof selfnum);

    for (int a = 1; a < MAXN; a++) {
        int digitsum = 0;
        int tmp = a;
        while (tmp) {
            digitsum += tmp % 10;
            tmp /= 10;
        }
        if (a + digitsum < MAXN) {
            selfnum[a + digitsum] = false;
        }
    }

    int N, K;
    cin >> N >> K;

    vector<int> selfnums;
    for (int a = 1; a <= N; a++) {
        if (selfnum[a]) {
            selfnums.push_back(a);
        }
    }

    cout << selfnums.size() << endl;
    while (K--) {
        int i;
        cin >> i;
        cout << selfnums[i - 1] << " ";
    }
}
