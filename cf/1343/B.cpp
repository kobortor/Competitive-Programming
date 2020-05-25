#include<bits/stdc++.h>

// Created by kobortor On 00:18:09 on 25-05-2020

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

        if ((n / 2) % 2 == 1) {
            cout << "NO\n";
        } else {
            vector<int> v(n);
            for (int i = 0; i < n / 2; i += 2) {
                v[i] = 6 * i + 2;
                v[i + 1] = 6 * i + 4;

                v[n - i - 1] = 6 * i + 1;
                v[n - i - 2] = 6 * i + 5;
            }

            cout << "YES\n";
            for (int i : v) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
}
