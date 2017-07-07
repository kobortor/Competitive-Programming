#include<bits/stdc++.h>

using namespace std;
template<typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using maxheap = priority_queue<T>;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2005;
const int MAXF = 505;

int T, H, F;

short acorn[MAXN][MAXN];
int dp[MAXF][MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int num_tests;
    cin >> num_tests;

    while(num_tests--) {
        memset(acorn, 0, sizeof(acorn));
        memset(dp, 0, sizeof(dp));
        cin >> T >> H >> F;

        for(int a = 1; a <= T; a++) {
            int K;
            cin >> K;

            while(K--) {
                int x;
                cin >> x;
                acorn[x][a]++;
            }
        }

        for(int a = H; a >= 1; a--) {
            int best1 = 0, best2 = 0;

            for(int b = 1; b <= T; b++) {
                dp[a % MAXF][b] = dp[(a + 1) % MAXF][b];
                int jumper = dp[(a + F) % MAXF][b];

                if(jumper > best1) {
                    best2 = best1;
                    best1 = jumper;
                } else {
                    best2 = max(best2, jumper);
                }
            }

            for(int b = 1; b <= T; b++) {
                if(dp[(a + F) % MAXF][b] == best1) {
                    dp[a % MAXF][b] = max(dp[a % MAXF][b], best2);
                } else {
                    dp[a % MAXF][b] = max(dp[a % MAXF][b], best1);
                }

                dp[a % MAXF][b] += acorn[a][b];
            }
        }

        cout << *max_element(dp[1], dp[1] + MAXF) << "\n";
    }

    int useless_zero;
    cin >> useless_zero;
}
