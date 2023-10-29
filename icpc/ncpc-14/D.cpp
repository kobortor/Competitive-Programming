#include<bits/stdc++.h>

// Created by $%U%$ On $%h%$:$%m%$:$%s%$ on $%D%$-$%M%$-$%Y%$

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> scores(int a1, int b1, int a2, int b2) {
    vector<int> v;
    for (int i = a1; i <= b1; i++) {
        for (int j = a2; j <= b2; j++) {
            v.push_back(i + j);
        }
    }
    sort(allof(v));
    return v;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    vector<int> v1 = scores(a1, b1, a2, b2);

    cin >> a1 >> b1 >> a2 >> b2;
    vector<int> v2 = scores(a1, b1, a2, b2);

    int n_win_1 = 0;
    int n_win_2 = 0;
    for (int i : v1) {
        n_win_1 += lower_bound(v2.begin(), v2.end(), i) - v2.begin();
        n_win_2 += v2.end() - upper_bound(v2.begin(), v2.end(), i);
    }

    if (n_win_1 > n_win_2) {
        cout << "Gunnar\n";
    } else if (n_win_1 < n_win_2) {
        cout << "Emma\n";
    } else {
        cout << "Tie\n";
    }
}
