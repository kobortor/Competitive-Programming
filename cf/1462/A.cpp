#include<bits/stdc++.h>

// Created by kobortor On 22:47:06 on 19-12-2020

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

        vector<int> v(n);
        for (int &vi : v) cin >> vi;

        int i = 0, j = n - 1;

        bool left = true;
        while (i <= j) {
            if (left) {
                cout << v[i++] << " ";
            } else {
                cout << v[j--] << " ";
            }

            left ^= true;
        }
        cout << "\n";
    }
}
