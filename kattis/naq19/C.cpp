#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e4 + 4;

ll voteA[MAXN];
ll voteB[MAXN];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int P, D;
    cin >> P >> D;

    while (P--) {
        int di, ai, bi;
        cin >> di >> ai >> bi;

        voteA[di] += ai;
        voteB[di] += bi;
    }

    int totCnt = 0;
    int totWasteA = 0;
    int totWasteB = 0;

    for (int a = 1; a <= D; a++) {
        int cnt = voteA[a] + voteB[a];
        int wasteA = 0, wasteB = 0;
        if (voteA[a] > voteB[a]) {
            wasteA = voteA[a] - ((cnt / 2) + 1);
            wasteB = voteB[a];
            cout << "A " << wasteA << " " << wasteB << "\n";
        } else {
            wasteA = voteA[a];
            wasteB = voteB[a] - ((cnt / 2) + 1);
            cout << "B " << wasteA << " " << wasteB << "\n";
        }

        totCnt += cnt;
        totWasteA += wasteA;
        totWasteB += wasteB;
    }

    double gap = (double)abs(totWasteA - totWasteB) / totCnt;
    cout << fixed << setprecision(15) << gap << "\n";
}
