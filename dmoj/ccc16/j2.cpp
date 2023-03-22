#include<bits/stdc++.h>

// Created by $%U%$ On $%h%$:$%m%$:$%s%$ on $%D%$-$%M%$-$%Y%$

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int grid[4][4];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> grid[i][j];
        }
    }

    bool good = true;
    int reference_sum = 0;
    for (int i = 0; i < 4; i++) {
        reference_sum += grid[0][i];
    }

    for (int i = 0; i < 4; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += grid[i][j];
        }
        if (sum != reference_sum) {
            good = false;
        }
    }

    for (int i = 0; i < 4; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += grid[j][i];
        }
        if (sum != reference_sum) {
            good = false;
        }
    }

    if (good) {
        cout << "magic\n";
    } else {
        cout << "not magic\n";
    }
}
