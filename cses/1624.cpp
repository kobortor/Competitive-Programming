#include<bits/stdc++.h>

// Created by kobortor On 18:52:06 on 27-01-2024

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string grid[8];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for (int i = 0; i < 8; i++) {
        cin >> grid[i];
    }
    vector<int> queens = {0,1,2,3,4,5,6,7};

    int ans = 0;
    do {
        bool good = true;
        for (int i = 0; i < 8 && good; i++) {
            if (grid[i][queens[i]] == '*') {
                good = false;
                break;
            }
            for (int j = i + 1; j < 8; j++) {
                if (abs(i - j) == abs(queens[i] - queens[j])) {
                    good = false;
                    break;
                }
            }
        }
        ans += good;
    } while (next_permutation(allof(queens)));
    cout << ans;
}
