#include<bits/stdc++.h>

// Created by kobortor On 16:24:25 on 27-05-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> odds, evens;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x % 2) {
                evens.push_back(x);
            } else {
                odds.push_back(x);
            }
        }

        if (evens.size() % 2) {
            bool good = false;
            for (int i : evens) 
                for (int j : odds)
                    good |= abs(i - j) == 1;

            cout << (good ? "YES\n" : "NO\n");
        } else {
            cout << "YES\n";
        }
    }
}
