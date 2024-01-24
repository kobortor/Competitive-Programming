#include<bits/stdc++.h>

// Created by kobortor On 18:41:43 on 21-01-2024

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
    while (n--) {
        int t;
        cin >> t;
        string a, b, c;
        cin >> a >> b >> c;

        bool good = false;
        for (int i = 0; i < t; i++) {
            if (a[i] != c[i] && b[i] != c[i]) {
                good = true;
            }
        }
        cout << (good ? "YES\n" : "NO\n");
    }
}
