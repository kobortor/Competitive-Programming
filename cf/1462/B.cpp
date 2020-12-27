#include<bits/stdc++.h>

// Created by kobortor On 23:13:29 on 19-12-2020

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
        string s;
        cin >> n >> s;

        bool good = false;
        for (int i = 0; i <= 4; i++) {
            if (s.substr(0, i) + s.substr(n - (4 - i), 4 - i) == "2020") {
                good = true;
                break;
            }
        }
        if (good) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
