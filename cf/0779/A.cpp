#include<bits/stdc++.h>

// Created by kobortor On 01:45:37 on 26-05-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> c1(5);
    vector<int> c2(5);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        c1[x - 1]++;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        c2[x - 1]++;
    }

    bool good = true;
    for (int i = 0; i < 5; i++) {
        good &= (c1[i] + c2[i]) % 2 == 0;
    }

    if (good) {
        int ans = 0;
        for (int i = 0; i < 5; i++) {
            ans += abs(c1[i] - c2[i]);
        }

        cout << ans / 4;
    } else {
        cout << -1;
    }
}
